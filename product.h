#pragma once
#ifndef USER_H
#define USER_H

class product
{
	int			ID;
	string		name,
				manufactorier,
				group,
				arrival,
				before_date;;
	double		price;	
	
public:
	product();
	product(int _ID, string _name, string _manufactorier, double _price,
		string _group, time_t _arrival, time_t _before_date);
	~product() {};
	product read_product(int base_number);
	friend ostream& operator << (ostream& os, const product& p);
	friend void find();
	double get_price() const { return price; }
	string get_group() const { return group; }
};

product::product()
{
	ID = 0;
	name = " ";
	manufactorier = " ";
	price = 0;
	group = " ";
	arrival = " ";
	before_date = " ";
}

product::product(int _ID, string _name, string _manufactorier, double _price,
	string _group, time_t _arrival, time_t _before_date)
{
	ID = _ID;
	name = _name;
	manufactorier = _manufactorier;
	price = _price;
	group = _group;
	arrival = _arrival;
	before_date = _before_date;
}

product product::read_product(int base_number)
{
	product temp;
	string line;

	temp.ID = base_number;
	stringstream product_info_path; product_info_path << "product_info/" << base_number << ".pb";
	ifstream in_info(product_info_path.str(), std::ios::binary | std::ios::out);
	if (in_info.is_open())
	{
		getline(in_info, line);
		line = remove_rn(line);
		temp.name = line;

		getline(in_info, line);
		line = remove_rn(line);
		temp.manufactorier = line;

		getline(in_info, line);
		line = remove_rn(line);
		temp.group = line;

		getline(in_info, line);
		line = remove_rn(line);
		temp.arrival = line;

		getline(in_info, line);
		line = remove_rn(line);
		temp.before_date = line;

		getline(in_info, line);
		line = remove_rn(line);
		temp.price = stof(line);
	}
	in_info.close();

	return temp;
}

ostream& operator << (ostream& os, const product& p)
{
	os << setw(5) << p.ID << setw(25) << p.name << setw(35) << p.manufactorier;
	os << setw(10) << p.price << setw(20) << p.group << setw(13) << p.arrival << setw(13) << p.before_date << endl;
	return os;
}

product new_product(int ind = 1, bool change = false)
{
	system("cls");
	char name[256]; char manufactorier[256]; int* price = new int(0);
	char group[256]; char arrival[256]; char before_date[256];
	int n = 1; stringstream path;

	if (!change) { while (file_exist(ind)) { ind++; }; }
	path << "product_info/" << ind << ".pb";

	set_color_console(Cyan, Black);
	cout << "\tВведите название товара:\t>> ";
	set_color_console(LightRed, Black);
	cin.getline(name, 256, '\n');

	set_color_console(Cyan, Black);
	cout << "\tВведите производителя товара:\t>> ";
	set_color_console(LightRed, Black);
	cin.getline(manufactorier, 256, '\n');

	set_color_console(Cyan, Black);
	cout << "\tВведите тип товара:\t\t>> ";
	set_color_console(LightRed, Black);
	cin.getline(group, 256, '\n');

	time_t currentTime = time(nullptr);
	struct tm* localTime = localtime(&currentTime);
	strftime(arrival, sizeof(arrival), "%d/%m/%Y", localTime);

	set_color_console(Cyan, Black);
	cout << "\tВведите срок годности d/m/Y\t>> ";
	set_color_console(LightRed, Black);
	cin.getline(before_date, 256, '\n');	
	
	set_color_console(Cyan, Black);
	cout << "\tВведите цену товара:\t\t>> ";
	set_color_console(LightRed, Black);
	var_cin(price, "\tВведите корректную цену");

	system("cls");
	ofstream out_1;
	out_1.open(path.str());
	if (out_1.is_open())
	{
		out_1 << name << endl << manufactorier << endl << group << endl << arrival << endl << before_date << endl << *price << endl;
	}
	out_1.close();

	product temp;
	temp = temp.read_product(ind);
	set_color_console(White, Black);
	cout << "\n\tНажимите любую клавишу для продолжения...";
	return temp;
}

#endif