#include<iostream>
#include<Windows.h>

class bad_length : public std::exception


{
public:
	const char* what() const override { return "�� ����� ����� ��������� �����! �� ��������"; }
};


int function(std::string str, int forbidden_length) {
	

	if (str.length() == forbidden_length) throw bad_length();


		return str.length();

};

void work(std::string* word,int* bad_l) {

	for (;;) {

		std::cout << "������� ��������� �����: ";
		std::cin >> *bad_l;

		std::cout << "������� �����: ";
		std::cin >> *word;

		try
		{
			std::cout << "����� ����� <<"<<*word <<">> ����� "<< function(*word, *bad_l) << std::endl;
		}

		catch (const bad_length& pff) { std::cout << pff.what() << std::endl; break; }
		catch (...) { std::cout << "����������� ������" << std::endl; break;}

		std::cout << std::endl;
	};

}


int main(int argc, char** argv) {

SetConsoleCP(1251);
SetConsoleOutputCP(1251);

int bad = 0;
std::string word_one;

work(&word_one, &bad);


	return 0;

}
