#include <iostream> //библиотека, предназначенная для реализации ввода-вывода в консоли. 
#include <fstream>//предоставляет функционал для считывания данных из файла и записи данных в файл.
#include <vector>//предназначен для использования векторов
#include <conio.h>//тобы использовать функцию getch(), которая читает один символ с клавиатуры, но не выводит его на экран;
#include <cstdlib>//заголовочный файл, который определяет функции для поиска, сортировки и преобразования типов данных
#include <string>//заголовочный файл, содержащий функции для работы с нуль-терминированными строками и различными функциями работы с памятью;
#include <sstream>//заголовочный файл с классами, функциями и переменными для организации работы со строками;
#include <iomanip>//для использования манипуляторов, например, setw (int w), который устанавливает ширину поля w.
#include<Windows.h>
using namespace std;

const char separator = '|';

void info() {
	system("color 9");//цвет букв 
	SYSTEMTIME stm; //Вывод текущей даты и времени осуществляется с помощью структуры 
	GetLocalTime(&stm);
	cout << "\n\nЗдравствуйте!\n" << endl;
	cout << "Текущая дата и время: " << stm.wDay << "." << stm.wMonth << "." << stm.wYear << "(" << stm.wHour << ":" << stm.wMinute << ")" << endl;
	cout << "Разработчик проекта:\n\t\tАвсиевич Юлия Владимировна" << endl;
	cout << "Руководитель проекта:\n\t\tГоворко Алина Вячеславовна" << endl;
	cout << "Год разработки: 2022" << endl << endl;
	puts("Нажмите любую клавишу, чтобы продолжить");// функция вывода, но может выводить только строки .
	_getch();//нужна для чтения одного символа с клавиатуры, этот символ на экран не выводится.
	system("cls");//очищает экран консоли
	system("color f");
}

void about_time() {//возможность вставки на страницу текущей даты и времени
	SYSTEMTIME stm;
	GetLocalTime(&stm);
	cout << "\n\nТекущая дата и время: " << stm.wDay << "." << stm.wMonth << "." << stm.wYear << "(" << stm.wHour << ":" << stm.wMinute << ")\n\n";
}

void about_programm() {//информация о разработчике, руководителе проекта, год разработки
	cout << "\n\nРазработчик проекта: Авсиевич Юлия Владимировна" << endl;
	cout << "Руководитель проекта: Говорко Алина Вячеславовна" << endl;
	cout << "Год разработки: 2022" << endl;
}

class User {
private:
	string login, password, status;
public:
	User(string login, string password, string status) {
		setLogin(login);
		setPassword(password);
		setStatus(status);
	}
	void setLogin(string login) {
		this->login = login;//это скрытый константный указатель, содержащий адрес объекта, который вызывает метод класса
	}
	void setPassword(string password) {
		this->password = password;
	}
	void setStatus(string status) {
		this->status = status;
	}
	void show_users(int i) {
		cout << "|  " << setw(4) << left << i << "|  " << setw(22) << login << "|  " << setw(21) << password << "| " << setw(7) << status << "|\n"
			<< "------------------------------------------------------------------\n";// Ширина поля отображения для следующего элемента в потоке
	}
	string getLogin() {
		return login;
	}
	string getPassword() {
		return password;
	}
	string getStatus() {
		return status;
	}
};

class Therapy {
private:
	string FIO;
	int year;
	int month;
	string service;
	int price;
public:
	Therapy() {}
	Therapy(string FIO, int year, int month, string service, int price) {
		setFIO(FIO);
		setYear(year);
		setMonth(month);
		setService(service);
		setPrice(price);
	}
	void setFIO(string FIO) {
		this->FIO = FIO;
	}
	void setYear(int year) {
		if (year < 0)
			return;
		this->year = year;
	}
	void setMonth(int month) {
		if (month < 0 && month >= 31)
			return;
		this->month = month;
	}
	void setService(string service) {
		this->service = service;
	}
	void setPrice(int price) {
		if (price < 0)
			return;
		this->price = price;
	}
	void show(int i)
	{
		cout << "|  " << setw(4) << left << i << "|  " << setw(30) << left << FIO << "|  " << setw(5) << year << "| "
			<< setw(6) << left << month << "   |  " << setw(29) << service << "| " << setw(10) << left << price << "|\n"
			<< "--------------------------------------------------------------------------------------------------------------\n";
	}

	string getFIO() {
		return FIO;
	}
	string getFIO_space() {
		string ss(FIO.begin(), find(FIO.begin(), FIO.end(), ' '));
		return ss;
	}
	int getYear() {
		return year;
	}
	int getMonth() {
		return month;
	}
	string getService() {
		return service;
	}
	int getPrice() {
		return price;
	}
	int x;
	int y;
	void clients();
	void sum();
	void search();
	void sort();
};

void head() {
	cout << "\n\t\t\t\tИнформация о клиентах\n"
		<< "--------------------------------------------------------------------------------------------------------------\n"
		<< "|  " << "id" << "  |\t\t" << "ФИО" << "\t\t| " << "год" << "|" << "месяц" << "|\t" << "услуга" << "\t\t  | " << "стоимость" << " |\n"
		<< "--------------------------------------------------------------------------------------------------------------\n";
}

void user_head() {
	cout << "\n\t\t\tИнформация о пользователях\n"
		<< "------------------------------------------------------------------------------------------------------\n"
		<< "|  " << "id" << "  |\t" << "login" << "\t\t|\t" << "password" << "\t| " << "status" << " |\n"
		<< "------------------------------------------------------------------------------------------------------\n";
}

void show_all(vector <Therapy> clients)//в эту функцию передается вектор объектов класса Therapy
{
	for (int i = 0; i < (int)clients.size(); i++)
	{
		int j = i + 1;
		clients[i].show(j);// j - id клиента, для каждого клиента вызывается метод show
	}
}

void show_users_all(vector <User> users) {
	for (int i = 0; i < (int)users.size(); i++)
	{
		int j = i + 1;
		users[i].show_users(j);
	}
}

void file_update(vector<Therapy> clients) { // перезапись всех данных в файл (обновление)
	ofstream out;
	out.open("DataTable.txt", ios::out | ios::trunc);
	if (out.is_open()) {
		for (int i = 0; i < clients.size(); i++) {
			out << clients[i].getFIO() << separator << clients[i].getYear() << separator << clients[i].getMonth() << separator << clients[i].getService()
				<< separator << clients[i].getPrice() << separator; // запись с разделителем
		}
	}
	out.close();
}

void users_file_update(vector <User> users) {
	ofstream out;
	out.open("UserTable.txt", ios::out | ios::trunc);//ios::out указывает на способность файла к выполнению  операций вывода.ios::trunc обусловливает уничтожение содержимого файла с заданным именем и усечение дли­ны файла до нуля.
	if (out.is_open()) {
		for (int i = 0; i < users.size(); i++) {
			out << users[i].getLogin() << " " << users[i].getPassword() << " " << users[i].getStatus() << " ";
		}
	}
	out.close();
}

vector<Therapy> read_file() // ф-ция для чтения файла, возвращает вектор клиентов
{
	Therapy client; // объект класса
	vector<Therapy> clients; //вектор клиентов
	string line; // строка для записи считывания
	ifstream in;
	int count = 0;
	in.open("DataTable.txt");
	if (in.is_open()) {
		while (getline(in, line)) {
			stringstream ss(line); // переменная для разделения считываемого
			while (getline(ss, line, separator)) {//редназначена для ввода данных из потока, например, для ввода данных из консольного окна. Если формально описывать ее функционал, то она извлекает данные из входного потока до строкового разделителя,
				switch (count) { //5 считываний, после которых счетчик обнуляется для нового считывания
				case 0: {
					client.setFIO(line);
					break;
				}
				case 1: {
					client.setYear(atoi(line.c_str()));//rонвертирует строку, на которую указывает параметр str, в величину типа int
					break;
				}
				case 2: {
					client.setMonth(atoi(line.c_str()));
					break;
				}
				case 3: {
					client.setService(line);
					break;
				}
				case 4: {
					client.setPrice(atoi(line.c_str()));
					break;
				}
				}
				count++;
				if (count == 5) {
					count = 0;
					clients.push_back(client); //запись считанных данных в вектор
				}
			}
		}
	}
	in.close();
	return clients;
}

vector<User> read_user_file() {
	string login, password, status;
	vector<User> users;
	ifstream in;
	in.open("UserTable.txt");

	if (in.is_open())
	{
		while (in >> login >> password >> status)
		{
			users.push_back(User(login, password, status));
		}
	}
	in.close();
	return users;
}

void login_menu();
void admin_menu();
void user_menu();

void authorization_menu() {
	info();
	cout << "-------------------------------------\n";
	cout << "|       Авторизация      |\n";
	cout << "-------------------------------------\n";
	cout << "1. Вход" << endl;
	cout << "2. Выход" << endl;
	int a;
	cin >> a;
	switch (a)
	{
	case 1: login_menu(); break;
	case 2: exit(0); break;
	default: cout << "Невозможно совершить действие. Проверьте ввод!\n" << endl;
		puts("Нажмите любую клавишу, чтобы продолжить");
		_getch();
		system("cls");
	}
}

void login_menu() {
	const string main_login = "Juls";//Главный админ системы, нельзя удалить
	const string main_password = "1111";
	string login;
	string password;
	bool error = false;
	int block = 0;
	while (block != 3) {
		if (block == 1) {
			cout << "Осталось " << 3 - block << " попытки!\n";
		}
		else if (block == 2) {
			cout << "Осталась " << 3 - block << " попытка!\n";
		}
		cout << "Введите логин: ";
		cin >> login;
		cout << "Введите пароль: ";
		cin >> password;
		if (login == main_login && password == main_password) {
			admin_menu();
		}
		else {
			vector<User> users = read_user_file(); // вызов функции чтения для получения данных обо всех учетных записях
			for (int i = 0; i < users.size(); i++) {
				if (login == users[i].getLogin() && password == users[i].getPassword()) {
					error = false;
					if (users[i].getStatus() == "admin") {
						admin_menu();
					}
					else if (users[i].getStatus() == "user") {
						user_menu();
					}
				}
			}

		}
		block++;
		if (block == 3) {
			error = true;
		}
		if (error) {
			puts("Ошибка входа!\nНажмите любую клавишу, чтобы продолжить");
			_getch();
			system("cls");
		}
	}
}

void admin_menu() {
	system("cls");
	cout << "-----------------------------------------------------------------" << endl;
	cout << "|\t\tМеню администратора\t\t|" << endl;
	cout << "-----------------------------------------------------------------" << endl << endl;
	cout << "0. Выход из учетной записи" << endl << endl;
	cout << "Управление учетными записями пользователей: " << endl;
	cout << "1. Просмотр всех учетных записей пользователей" << endl;
	cout << "2. Добавление учетной записи пользователя" << endl;
	cout << "3. Редактирование учетной записи пользователя" << endl;
	cout << "4. Удаление учетной записи пользователя" << endl << endl;
	cout << "Работа с файлом данных: " << endl;
	cout << "5. Создать файл" << endl;
	cout << "6. Открыть файл" << endl;
	cout << "7. Удалить файл" << endl << endl;
	cout << "Работа с данными: " << endl;
	cout << "8. Просмотр всех данных" << endl;
	cout << "9. Добавление записи" << endl;
	cout << "10. Удаление записи (для этого необходимо \nввести порядковый номер конкретной записи)" << endl;
	cout << "11. Редактирование записи (для этого необходимо \nввести порядковый номер конкретной записи)" << endl << endl;
	cout << "Выберите пункт ..." << endl;
	int i; cin >> i;
	while (i != 0) {
		switch (i) {
		case 1: {
			vector<User> users = read_user_file();
			if (users.empty()) {
				cout << "Файл пуст!";
				break;
			}
			user_head();
			show_users_all(users);
			about_programm();
			about_time();
			break;
		}
		case 2: {
			string login, password, status; int ans; bool check = true;
			vector<User> users = read_user_file();
			bool inc = true;
			while (check) {
				cout << "Введите логин: "; cin >> login;
				for (int i = 0; i < users.size(); i++) {
					if (login != users[i].getLogin() && login != "Juls") {//нельзя создать новую уч.запись с логином главного админа
						inc = false;
					}
					else {
						inc = true;
						i = users.size();
					}
				}
				if (users.empty()) {
					inc = false;
				}
				if (!inc) {
					check = false;
				}
				else {
					cout << "Такой пользователь уже есть!" << endl;
				}
			}
			cout << "Введите пароль: "; cin >> password;
			check = true;
			while (check) {
				cout << "Введите статус:\n1. админ\n2. пользователь\n"; cin >> ans;
				switch (ans) {
				case 1: {
					status = "admin";
					check = false;
					break;
				}
				case 2: {
					status = "user";
					check = false;
					break;
				}
				default: cout << "Ошибка!\n";
				}
			}
			fstream out;
			out.open("UserTable.txt", ios_base::app);//добавление новой уч.записи
			if (out.is_open()) {
				out << login << " " << password << " " << status << " ";//запись в поток
			}
			out.close();
			cout << "Запись успешно создана!" << endl;
			break;
		}
		case 3: {
			string login, password, status;
			bool check = true;
			vector<User> users = read_user_file();
			if (users.empty()) {//проверка файла на пустоту
				cout << "Файл пуст!";
				break;
			}
			user_head();
			show_users_all(users);
			int id;
			cout << "Введите id пользователя, которого хотите изменить: "; cin >> id;
			id -= 1;
			while (check) {
				cout << "1. Изменить логин" << endl;
				cout << "2. Изменить пароль" << endl;
				cout << "3. Изменить статус" << endl;
				cout << "4. Выйти" << endl;
				int num; cin >> num;
				switch (num) {
				case 1: {
					bool check2 = true;
					while (check2) {
						bool inc;
						cout << "логин: "; cin >> login;
						for (int i = 0; i < users.size(); i++) {
							if (login != users[i].getLogin() && login != "Juls") {
								inc = false;
							}
							else {
								inc = true;
								i = users.size();
							}
						}
						if (!inc) {
							check2 = false;
						}
						else {
							cout << "Такой пользователь уже есть!" << endl;
						}
					}
					users[id].setLogin(login);//инициализация переменной логина пользователя
					break;
				}
				case 2: {
					cout << "пароль: "; cin >> password;
					users[id].setPassword(password);//инициализация переменной пароля 
					break;
				}
				case 3: {
					int ans;
					bool check2 = true;
					while (check2) {
						cout << "статус:\n1.админ\n2.пользователь\n"; cin >> ans;
						switch (ans) {//выбор статуса
						case 1: {
							users[id].setStatus("admin");
							check2 = false;
							break;
						}
						case 2: {
							users[id].setStatus("user");
							check2 = false;
							break;
						}
						default: cout << "Ошибка!\n";
						}
					}
					break;
				}
				case 4: {
					check = false;
					break;
				}
				}
			}
			users_file_update(users);
			cout << "Запись успешно изменена!" << endl;
			break;
		}
		case 4: {
			vector<User> users = read_user_file();
			string ans;
			if (read_user_file().empty()) {
				cout << "Файл пуст!";
				break;
			}
			user_head();
			show_users_all(users);
			int id;
			cout << "Введите id пользователя, которого хотите удалить: "; cin >> id;
			cout << "Вы действительно хотите удалить запись?(y/n): "; cin >> ans;
			if (ans == "y" || ans == "yes") {
				id -= 1;
				if (id > 0 && id < users.size() - 1) {//удаление между первым и последним элементом
					users.erase(users.cbegin() + id);
				}
				else if (id == 0) {
					users.erase(users.begin());//удаление первого элемента
				}
				else if (id == users.size() - 1) {
					users.pop_back();//удаление последнего эл-та
				}
				users_file_update(users);
				cout << "Запись успешно удалена\n";
			}
			else {
				cout << "Удаление отменено!\n";
			}
			break;
		}
		case 5: {
			string file_name;
			cout << "Для создания введите название файла с его расширением: "; cin >> file_name;
			ofstream ofs(file_name);//создание файла
			ofs.close();
			cout << "Файл успешно создан!\n";
			about_time();
			break;

		}
		case 6: {
			string file_name, line;
			cout << "Для открытия введите название файла с его расширением: "; cin >> file_name;
			ifstream in(file_name);
			try {//обработка исключений
				if (!in.is_open()) {//создание исключения на случай не открытия файла, при срабатывании которого catch ловит его
					throw "Ошибка открытия файла...";
					about_time();
				}
				if (in.is_open())
				{
					cout << "\nОткрытие файла...\n\n";
					while (getline(in, line))
					{
						cout << line << endl;
					}
					cout << endl;
				}
				in.close();
				if (line.empty()) {
					throw "Файл пуст!";
					about_time();
				}
			}
			catch (const char* msg) {//если словил искл. то выведет его пользователю
				cout << msg << endl;
			}
			break;
		}
		case 7: {
			string ans;
			char file_name[80];
			cout << "Для удаления введите название файла с его расширением: "; cin >> file_name;
			cout << "Вы действительно хотите удалить файл?(y/n): "; cin >> ans;
			if (ans == "y" || ans == "yes") {
				remove(file_name); //удалить
				cout << "Файл удалён!\n";
				about_time();
			}
			else {
				cout << "Удаление отменено!\n";
				about_time();
			}
			break;
		}
		case 8: {
			try {
				vector<Therapy> clients = read_file();
				if (clients.empty()) {
					throw "Файл пуст!";
					break;
				}
				head();
				show_all(clients);
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
			about_programm();
			about_time();
			break;
		}
		case 9: {
			string  FIO, s_year, s_month, service, s_price;
			cin.ignore();//игнорирование оператора cin
			cout << "Введите ФИО: "; getline(cin, FIO); FIO.push_back(separator);
			cout << "Введите год: "; getline(cin, s_year); s_year.push_back(separator);
			cout << "Введите месяц(цифрой): "; getline(cin, s_month); s_month.push_back(separator);
			cout << "Введите название услуги: "; getline(cin, service); service.push_back(separator);
			cout << "Введите стоимость услуги: "; getline(cin, s_price); s_price.push_back(separator);

			ofstream out;
			out.open("DataTable.txt", ofstream::app);
			if (out.is_open()) {
				out << FIO << s_year << s_month << service << s_price;
			}
			out.close();
			cout << "Запись успешно создана!" << endl;
			break;
		}
		case 10: {
			string ans;
			vector<Therapy> clients = read_file();
			if (clients.empty()) {
				cout << "Файл пуст!";
				break;
			}
			head();
			show_all(clients);
			int id;
			cout << "Введите id клиента, которого хотите удалить: "; cin >> id;
			cout << "Вы действительно хотите удалить запись?(y/n): "; cin >> ans;
			if (ans == "y" || ans == "yes") {
				id -= 1;
				if (id > 0 && id < clients.size() - 1) {
					clients.erase(clients.cbegin() + id);
				}
				else if (id == 0) {
					clients.erase(clients.begin());
				}
				else if (id == clients.size() - 1) {
					clients.pop_back();
				}
				file_update(clients);
				cout << "Запись успешно удалена!\n";
			}
			else {
				cout << "Удаление отменено!\n";
			}
			break;
		}
		case 11: {
			string  FIO, s_year, s_month, service, s_price;
			bool check = true;
			vector<Therapy> clients = read_file();
			if (clients.empty()) {
				cout << "Файл пуст!";
				break;
			}
			head();
			show_all(clients);
			int id;
			cout << "Введите id клиента, которого хотите изменить: "; cin >> id;
			id -= 1;
			while (check) {
				cout << "1. Изменить ФИО" << endl;
				cout << "2. Изменить год" << endl;
				cout << "3. Изменить месяц(цифрой)" << endl;
				cout << "4. Изменить услугу" << endl;
				cout << "5. Изменить стоимость услуги" << endl;
				cout << "6. Выйти" << endl;
				int num; cin >> num;
				switch (num) {
				case 1: {
					cin.ignore();
					cout << "Введите ФИО: "; getline(cin, FIO);
					clients[id].setFIO(FIO);
					break;
				}
				case 2: {
					cin.ignore();
					cout << "Введите год: "; getline(cin, s_year);
					clients[id].setYear(atoi(s_year.c_str()));
					break;
				}
				case 3: {
					cin.ignore();
					cout << "Введите месяц(цифрой): "; getline(cin, s_month);
					clients[id].setMonth(atoi(s_month.c_str()));
					break;
				}
				case 4: {
					cin.ignore();
					cout << "Введите название услуги: "; getline(cin, service);
					clients[id].setService(service);
					break;
				}
				case 5: {
					cin.ignore();
					cout << "Введите стоимость услуги: "; getline(cin, s_price);
					clients[id].setPrice(atoi(s_price.c_str()));
					break;
				}
				case 6: {
					check = false;
					break;
				}
				}
			}
			file_update(clients);
			cout << "Запись успешно изменена!\n";
			break;
		}
		}
		puts("Нажмите любую клавишу, чтобы продолжить");
		_getch();
		system("cls");
		admin_menu();
	}
	system("cls");
	authorization_menu();
}

void user_menu() {
	system("cls");
	cout << "-------------------------------------------------" << endl;
	cout << "|\t\tМеню пользователя\t\t|" << endl;
	cout << "-------------------------------------------------" << endl << endl;
	cout << "0. Выход из учетной записи" << endl << endl;
	cout << "1. Просмотр данных" << endl;
	cout << "2. Для месяца x года y вывести список клиентов" << endl;
	cout << "3. Вывести сумму, которая была заработана \nза интересующий месяц" << endl;
	cout << "4. Поиск и фильтрация" << endl;
	cout << "5. Сортировка" << endl << endl;
	cout << "Выберите пункт ..." << endl;
	Therapy client;
	int i;
	cin >> i;
	while (i != 0) {
		switch (i) {
		case 1: {
			vector<Therapy> clients = read_file();
			if (read_file().empty()) {
				cout << "Файл пуст!";
				break;
			}
			head();
			show_all(clients);
			break;
		}
		case 2: {
			client.clients();
			break;
		}
		case 3: {
			client.sum();
			break;
		}
		case 4: {
			client.search();
			break;
		}
		case 5: {
			client.sort();
			break;
		}
		}
		puts("Нажмите любую клавишу, чтобы продолжить");
		_getch();
		system("cls");
		user_menu();
	}
	system("cls");
	authorization_menu();
}

void Therapy::clients() {
	vector<Therapy> clients = read_file();
	cout << "Введите месяц:(цифрой) "; cin >> x;
	while (true) {//проверка ввода
		if (cin.fail() || x > 12 || x < 1) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Ошибка! " << endl;
			cin >> x;
		}
		if (!cin.fail() && x <= 12 && x >= 1) break;
	}
	cout << "Введите год: "; cin >> y;
	while (true) {//проверка ввода
		if (cin.fail() || y > 2022 || y < 1900) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Ошибка! " << endl;
			cin >> y;
		}
		if (!cin.fail() && y <= 2022 && y >= 1900) break;
	}
	int sum = 0;
	for (int i = 0; i < clients.size(); i++)
	{
		if (y == clients[i].getYear() && x == clients[i].getMonth()) {
			sum += clients[i].getPrice();
		}
	}
	head();
	int client_count = 0;
	for (int i = 0; i < clients.size(); i++)
	{
		if (y == clients[i].getYear() && x == clients[i].getMonth()) {//если х и у совпали с существующими данными
			client_count++;
			clients[i].show(i);
		}
	}
	if (client_count == 0) {
		cout << "\nТакой клиент не найден!\n" << endl;
	}
}

void Therapy::sum() {
	vector<Therapy> clients = read_file();
	int sum = 0;//переменная для подсчета суммы
	cout << "Введите месяц (цифрой) ";
	cin >> x;
	while (true) {//проверка ввода
		if (cin.fail() || x > 12 || x < 1) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Ошибка! " << endl;
			cin >> x;
		}
		if (!cin.fail() && x <= 12 && x >= 1) break;
	}

	cout << "Введите год ";
	cin >> y;
	while (true) {//проверка ввода
		if (cin.fail() || y > 2022 || y < 1900) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Ошибка! " << endl;
			cin >> y;
		}
		if (!cin.fail() && y <= 2022 && y >= 1900) break;
	}
	for (int i = 0; i < clients.size(); i++)
	{
		if (y == clients[i].getYear() && x == clients[i].getMonth()) {
			sum += clients[i].getPrice();
		}
	}
	cout << "\nСумма, заработанная за интересующий месяц: " << sum << endl << endl;
}

void Therapy::search() {
	vector<Therapy> clients = read_file();
	string FIO, service;
	int year, month, price;
	int ans;
	cout << "Поиск по:\n1.ФИО\n2.году\n3.месяцу\n4.услуге\n5.цене\n"; cin >> ans;
	switch (ans) {
	case 1: {
		int client_count = 0;
		cin.ignore();
		cout << "Введите ФИО: "; getline(cin, FIO);
		head();
		for (int i = 0; i < clients.size(); i++)
		{
			if (FIO == clients[i].getFIO_space() || FIO == clients[i].getFIO()) {
				client_count++;
				clients[i].show(i + 1);
			}
		}
		if (client_count == 0) {
			cout << "\nТакой клиент не найден!\n" << endl;
		}
		break;
	}
	case 2: {
		int client_count = 0;
		cout << "Введите год: "; cin >> year;
		head();
		for (int i = 0; i < clients.size(); i++)
		{
			if (year == clients[i].getYear()) {
				client_count++;
				clients[i].show(i + 1);
			}
		}
		if (client_count == 0) {
			cout << "\nТакой клиент не найден!\n" << endl;
		}
		break;
	}
	case 3: {
		int client_count = 0;
		cout << "Введите месяц(цифрой): "; cin >> month;
		head();
		for (int i = 0; i < clients.size(); i++)
		{
			if (month == clients[i].getMonth()) {
				client_count++;
				clients[i].show(i + 1);
			}
		}
		if (client_count == 0) {
			cout << "\nТакой клиент не найден!\n" << endl;
		}
		break;
	}
	case 4: {
		int client_count = 0;
		cin.ignore();
		cout << "Введите услугу: "; getline(cin, service);
		head();
		for (int i = 0; i < clients.size(); i++)
		{
			if (service == clients[i].getService()) {
				client_count++;
				clients[i].show(i + 1);
			}
		}
		if (client_count == 0) {
			cout << "\nТакой клиент не найден!\n" << endl;
		}
		break;
	}
	case 5: {
		int client_count = 0;
		cout << "Введите стоимость услуги: "; cin >> price;
		head();
		for (int i = 0; i < clients.size(); i++)
		{
			if (price == clients[i].getPrice()) {
				client_count++;
				clients[i].show(i + 1);
			}
		}
		if (client_count == 0) {
			cout << "\nТакой клиент не найден!\n" << endl;
		}
		break;
	}
	default: cout << "Данных не найдено!\n";
	}

}

void Therapy::sort() {
	vector<Therapy> clients = read_file();
	int ans;
	cout << "Сортировать по:\n1.ФИО\n2.году\n3.месяцу\n4.услуге\n5.цене\n"; cin >> ans;
	cout << "Сортировка..." << endl;
	switch (ans) {
	case 1: {
		vector< Therapy> sorted_clients = clients;
		vector<string> sorter;
		for (int i = 0; i < sorted_clients.size(); i++) {
			sorter.push_back(sorted_clients[i].getFIO());
		}
		string temp;
		Therapy temp_client;
		for (int i = 0; i < sorted_clients.size() - 1; i++) {
			for (int j = 0; j < sorted_clients.size() - i - 1; j++) {
				if (sorter[j] > sorter[j + 1]) {
					temp = sorter[j];
					temp_client = sorted_clients[j];
					sorter[j] = sorter[j + 1];
					sorted_clients[j] = sorted_clients[j + 1];
					sorter[j + 1] = temp;
					sorted_clients[j + 1] = temp_client;
				}
			}
		}
		head();
		show_all(sorted_clients);
		break;
	}
	case 2: {
		vector< Therapy> sorted_clients = clients;
		vector<int> sorter;
		for (int i = 0; i < sorted_clients.size(); i++) {
			sorter.push_back(sorted_clients[i].getYear());
		}
		int temp;
		Therapy temp_client;
		for (int i = 0; i < sorted_clients.size() - 1; i++) {
			for (int j = 0; j < sorted_clients.size() - i - 1; j++) {
				if (sorter[j] > sorter[j + 1]) {
					temp = sorter[j];
					temp_client = sorted_clients[j];
					sorter[j] = sorter[j + 1];
					sorted_clients[j] = sorted_clients[j + 1];
					sorter[j + 1] = temp;
					sorted_clients[j + 1] = temp_client;
				}
			}
		}
		head();
		show_all(sorted_clients);
		break;
	}
	case 3: {
		vector< Therapy> sorted_clients = clients;
		vector<int> sorter;
		for (int i = 0; i < sorted_clients.size(); i++) {
			sorter.push_back(sorted_clients[i].getMonth());
		}
		int temp;
		Therapy temp_client;
		for (int i = 0; i < sorted_clients.size() - 1; i++) {
			for (int j = 0; j < sorted_clients.size() - i - 1; j++) {
				if (sorter[j] > sorter[j + 1]) {
					temp = sorter[j];
					temp_client = sorted_clients[j];
					sorter[j] = sorter[j + 1];
					sorted_clients[j] = sorted_clients[j + 1];
					sorter[j + 1] = temp;
					sorted_clients[j + 1] = temp_client;
				}
			}
		}
		head();
		show_all(sorted_clients);
		break;
	}
	case 4: {
		vector< Therapy> sorted_clients = clients;
		vector<string> sorter;
		for (int i = 0; i < sorted_clients.size(); i++) {
			sorter.push_back(sorted_clients[i].getService());
		}
		string temp;
		Therapy temp_client;
		for (int i = 0; i < sorted_clients.size() - 1; i++) {
			for (int j = 0; j < sorted_clients.size() - i - 1; j++) {
				if (sorter[j] > sorter[j + 1]) {
					temp = sorter[j];
					temp_client = sorted_clients[j];
					sorter[j] = sorter[j + 1];
					sorted_clients[j] = sorted_clients[j + 1];
					sorter[j + 1] = temp;
					sorted_clients[j + 1] = temp_client;
				}
			}
		}
		head();
		show_all(sorted_clients);
		break;
	}
	case 5: {
		vector< Therapy> sorted_clients = clients;
		vector<int> sorter;
		for (int i = 0; i < sorted_clients.size(); i++) {
			sorter.push_back(sorted_clients[i].getPrice());
		}
		int temp;
		Therapy temp_client;
		for (int i = 0; i < sorted_clients.size() - 1; i++) {
			for (int j = 0
				; j < sorted_clients.size() - i - 1; j++) {
				if (sorter[j] > sorter[j + 1]) {
					temp = sorter[j];
					temp_client = sorted_clients[j];
					sorter[j] = sorter[j + 1];
					sorted_clients[j] = sorted_clients[j + 1];
					sorter[j + 1] = temp;
					sorted_clients[j + 1] = temp_client;
				}
			}
		}
		head();
		show_all(sorted_clients);
		break;
	}
	default: cout << "Данных не найдено!\n";
	}
}

int main() {

	authorization_menu();
}