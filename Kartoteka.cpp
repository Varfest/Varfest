#include "Kartoteka.h"


void DataInitialization()
{
	ofstream _buf("Budder.txt");

	if (!_buf)
		cout << "Ошибка Создания буферного файла!" << endl;
	_buf.close();

}

void DataEntry()
{
	string _surname;
	string _name;
	string _dolzh;
	string _stazhe;
	string _datarozh;
	int _oklad;
	int n;

	cout << "Введите количество данных: ";
	cin >> n;

	ofstream record("Buffer.txt", ios::app);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			cout << "Фамилия: ";
			cin >> _surname;

			cout << "Имя: ";
			cin >> _name;

			cout << "Дата рождения: ";
			cin >> _datarozh;

			cout << "Должность: ";
			cin >> _dolzh;

			cout << "Стаж: ";
			cin >> _stazhe;

			cout << "Оклад: ";
			cin >> _oklad;

			record << _surname << endl;
			record << _name << endl;
			record << _datarozh << endl;
			record << _dolzh << endl;
			record << _stazhe << endl;
			if (i < n - 1)
				record << _oklad << endl;
			else
				record << _oklad;

			cout << "______________________________" << endl;

		}
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	record.close();

}

void DataReading(string fileName)
{

	ifstream reading(fileName);
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {

			string _surname;
			string _name;
			string _dolzh;
			string _stazhe;
			string _datarozh;
			int _oklad;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> _surname;
				reading >> _name;
				reading >> _datarozh;
				reading >> _dolzh;
				reading >> _stazhe;
				reading >> _oklad;

				record << _surname << endl;
				record << _name << endl;
				record << _datarozh << endl;
				record << _dolzh << endl;
				record << _stazhe << endl;
				if (i < n - 1)
					record << _oklad << endl;
				else
					record << _oklad;

			}

			cout << "Данные считаны!" << endl;

		}
		else
			cout << "Ошибка открытия буфера!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	reading.close();
	record.close();

}

void Print()
{
	ifstream reading("Buffer.txt");
	if (reading) {

		string _surname;
		string _name;
		string _dolzh;
		string _stazhe;
		string _datarozh;
		string _oklad;
		int n;
		reading >> n;
		cout << "Количество данных: " << n << endl << endl;
		for (int i = 0; i < n; i++) {
			cout << "Сотрудник №: " << i + 1 << endl;

			reading >> _surname;
			cout << "Фамилия: " << _surname << endl;
			reading >> _name;
			cout << "Имя: " << _name << endl;
			reading >> _datarozh;
			cout << "Дата рождения: " << _datarozh << endl;
			reading >> _dolzh;
			cout << "Должность: " << _dolzh << endl;
			reading >> _stazhe;
			cout << "Стаж: " << _stazhe << endl;
			reading >> _oklad;
			cout << "Оклад: " << _oklad << endl;

			cout << "_____________________________" << endl;

		}

	}
	else
		cout << "Ошибка открытия файла!" << endl;

	reading.close();

}

bool DataCleaning()
{

	bool clear = false;
	fstream _buf("Buffer_.txt", ios::out);

	if(!_buf)
		cout << "Ошибка открытия буфера!" << endl;

	_buf.clear();

	if (_buf.peek() == EOF)
		clear = true;
	else
		clear = false;

	_buf.close();

	return clear;


}

void DataChange()
{

	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {

			string _surname;
			string _name;
			string _dolzh;
			string _stazhe;
			string _datarozh;
			int _oklad;
			int n, _n;
			reading >> n;

			cout << "Выберите номер изменяемого элемента (от 1 до " << n << "): ";
			cin >> _n;
			_n--;
			system("cls");

			record << n << endl;

			if (_n >= 0 && _n < n) {

				for (int i = 0; i < n; i++) {
					if (i != _n) {
						reading >> _surname;
						record << _surname << endl;

						reading >> _name;
						record << _name << endl;

						reading >> _datarozh;
						record << _datarozh << endl;

						reading >> _dolzh;
						record << _dolzh << endl;

						reading >> _stazhe;
						record << _stazhe << endl;

						reading >> _oklad;
						if (i < n - 1)
							record << _oklad << endl;
						else
							record << _oklad;
					}
					else {

						cout << "Фамилия: ";
						cin >> _surname;

						cout << "Имя: ";
						cin >> _name;

						cout << "Дата рождения: ";
						cin >> _datarozh;

						cout << "Должность: ";
						cin >> _dolzh;

						cout << "Стаж: ";
						cin >> _stazhe;

						cout << "Оклад: ";
						cin >> _oklad;

						record << _surname << endl;
						record << _name << endl;
						record << _datarozh << endl;
						record << _dolzh << endl;
						record << _stazhe << endl;
						if (i < n - 1)
							record << _oklad << endl;
						else
							record << _oklad;

						reading >> _surname;
						reading >> _name;
						reading >> _datarozh;
						reading >> _dolzh;
						reading >> _stazhe;
						reading >> _oklad;
					}

				}

				cout << "Данные изменены!" << endl;
			}
			else
				cout << "Номер введен неверно!" << endl;
		}
		else
			cout << "Ошибка открытия файла!" << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	record.close();
	reading.close();

	remove("Buffer_.txt");
}

void Copy()
{

	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);

	if (reading) {
		if (record) {

			string _surname;
			string _name;
			string _dolzh;
			string _stazhe;
			string _datarozh;
			int _oklad;
			int n;
			reading >> n;
			record << n << endl;
			for (int i = 0; i < n; i++) {
				reading >> _surname;
				record << _surname << endl;

				reading >> _name;
				record << _name << endl;

				reading >> _datarozh;
				record << _datarozh << endl;

				reading >> _dolzh;
				record << _dolzh << endl;

				reading >> _stazhe;
				record << _stazhe << endl;

				reading >> _oklad;
				if (i < n - 1)
					record << _oklad << endl;
				else
					record << _oklad;

			}

		}
		else
			cout << "Ошибка открытия файла!" << endl;
	}
	else
		cout << "Ошибка открытия буфера!" << endl;

	reading.close();
	record.close();

}

int AmountOdData()
{

	ifstream _buf("Buffer.txt");
	int n;

	if (_buf) {
		_buf >> n;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	_buf.close();

	return n;
}

void DeleteData()
{

	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {

			string _surname;
			string _name;
			string _dolzh;
			string _stazhe;
			string _datarozh;
			int _oklad;
			int n, _n;

			reading >> n;
			int b = n - 1;

			cout << "Выберите номер изменяемого элемента (от 1 до " << n << "): ";
			cin >> _n;
			_n--;
			system("cls");

			record << b << endl;

			if (_n >= 0 && _n < n) {

				for (int i = 0; i < n; i++) {
					if (i != _n) {
						reading >> _surname;
						record << _surname << endl;

						reading >> _name;
						record << _name << endl;

						reading >> _datarozh;
						record << _datarozh << endl;

						reading >> _dolzh;
						record << _dolzh << endl;

						reading >> _stazhe;
						record << _stazhe << endl;

						reading >> _oklad;
						if (i < n - 1)
							record << _oklad << endl;
						else
							record << _oklad;
					}
					else {

						reading >> _surname;
						reading >> _name;
						reading >> _datarozh;
						reading >> _dolzh;
						reading >> _stazhe;
						reading >> _oklad;
					}

				}

				cout << "Данные удалены!" << endl;
			}
			else
				cout << "Номер введен неверно!" << endl;
		}
		else
			cout << "Ошибка открытия файла!" << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	record.close();
	reading.close();

	remove("Buffer_.txt");

}

void AddData()
{

	string _surname;
	string _name;
	string _dolzh;
	int _stazhe;
	string _datarozh;
	int _oklad;
	int n = AmountOdData() + 1;

	ofstream record("Buffer.txt", ios::app);
	ofstream record_("Buffer.txt", ios::out | ios::in);

	if (record_) {
		record_ << n << endl;
	}
	else
		cout << "Ошибка открытия буферного файла!" << endl;

	if (record) {
		record << endl;
		cout << "Фамилия: ";
		cin >> _surname;

		cout << "Имя: ";
		cin >> _name;

		cout << "Дата рождения: ";
		cin >> _datarozh;

		cout << "Должность: ";
		cin >> _dolzh;

		cout << "Стаж: ";
		cin >> _stazhe;

		cout << "Оклад: ";
		cin >> _oklad;

		record << _surname << endl;
		record << _name << endl;
		record << _datarozh << endl;
		record << _dolzh << endl;
		record << _stazhe << endl;
		record << _oklad << endl;
		
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	record.close();
	record_.close();
}

void SaveData(string fileName)
{

	ifstream reading("Buffer.txt");
	ofstream record(fileName, ios::out);

	if (reading) {
		if (record) {
			string _surname;
			string _name;
			string _dolzh;
			string _stazhe;
			string _datarozh;
			int _oklad;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> _surname;
				record << _surname << endl;

				reading >> _name;
				record << _name << endl;

				reading >> _datarozh;
				record << _datarozh << endl;

				reading >> _dolzh;
				record << _dolzh << endl;

				reading >> _stazhe;
				record << _stazhe << endl;

				reading >> _oklad;
				if (i < n - 1)
					record << _oklad << endl;
				else
					record << _oklad;

			}
			cout << "Данные сохранены в файле " << fileName << endl;


		}
		else
			cout << "Ошибка открытия буфера!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	record.close();
	reading.close();
		
}

void Poisk()
{
	string g;
	cout << "Введите фамилию: ";
	cin >> g;

	ifstream reading("Buffer.txt");
	if (reading) {

		string _surname;
		string _name;
		string _dolzh;
		string _stazhe;
		string _datarozh;
		string _oklad;
		int n;

		reading >> n;
		cout << "Количество данных: " << n << endl << endl;
		for (int i = 0; i < n; i++) {
			reading >> _surname;
			reading >> _name;
			reading >> _datarozh;
			reading >> _dolzh;
			reading >> _stazhe;
			reading >> _oklad;
			if (g == _surname)
			{
				cout << "Сотрудник №: " << i + 1 << endl;
				cout << "Фамилия: " << _surname << endl;
				cout << "Имя: " << _name << endl;
				cout << "Дата рождения: " << _datarozh << endl;
				cout << "Должность: " << _dolzh << endl;
				cout << "Стаж: " << _stazhe << endl;
				cout << "Оклад: " << _oklad << endl;

				cout << "_____________________________" << endl;

			}
			
		}

	}
	else
		cout << "Ошибка открытия файла!" << endl;

	reading.close();

}
