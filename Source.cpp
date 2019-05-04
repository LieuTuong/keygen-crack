#include<iostream>
#include<string>
#include<sstream>

std::string toString(size_t n)
{
    std::stringstream ss;
	std::string tmp;

	ss << n;
	ss >> tmp;
	return tmp;

}

bool checkName(std::string inputName)
{
	for (int i = 0; i < inputName.length(); i++)
	{
		if (inputName[i] < 65 || inputName[i]>122 || inputName[i] > 90 && inputName[i] < 97)
			return false;
	}
	return true;
}

std::string generateKey(std::string inputName)
{
	size_t res=0;
	for (int i = 0; i < inputName.length(); i++)
	{
		if (inputName[i] >= 97 && inputName[i] <= 122)
			inputName[i] -= 32;
		res += inputName[i] ;
	}
	res ^= 0x5678;
	res ^= 0x1234;
	return toString(res);
}
int main()
{
	std::string name;
	bool validName;

	do
	{
		std::cout << "\nInput name: ";
		getline(std::cin, name);
	    validName = checkName(name);
		if (validName = false)
		{
			std::cout << "\nInvalid name, name is only composed of letters [a-z|A-Z]. Please try again!! ";
		}
	} while (validName = false);
	
	
	std::cout << "\nValid serial is: " << generateKey(name)<<std::endl;
	
	system("pause");
	return 0;

}