#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

class Address
{
private:
	std::string town;
	std::string strit;
	int house;
	int apart;
	std::string output_adress{};
	char temp;

public:
	Address(std::string town, std::string strit, int house, int apart)
	{
		this->town = town;
		this->strit = strit;
		this->house = house;
		this->apart = apart;
		this->temp = temp;
	}

	Address()
	{
		town = " ";
		strit = " ";
		house = 0;
		apart = 0;
		temp = ' ';
	}


	std::string get_output_address()
	{
		output_adress = town + " , " + strit + " , " + std::to_string(house) + " , " + std::to_string(apart);
		return output_adress;
	}


	int get_town()
	{
		char t = town.at(0);
		int t1 = (int)t;
		return t1;
	}
};

std::string* mass_addr(int N)
{
	std::string* addr = new std::string[N]{};
	return addr;
}

void del(Address* addr, int N)
{
	delete[]addr;
	addr = NULL;
}

void sort(Address* address, int N)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N - 1; j++)
		{
			if (address[j].get_town() > address[j + 1].get_town())
			{
				Address temp = address[j];
				address[j] = address[j + 1];
				address[j + 1] = temp;
			}
		}
}

void out_adr(Address* address, int N)
{
	std::ofstream adr1("out.txt");
	if (adr1.is_open())
	{
		adr1 << N << std::endl;
		for (int i = 0; i < N; i++)
		{
			adr1 << address[i].get_output_address() << std::endl;

		}
	}
	else {
		std::cout << "Ошибка открытия файла!" << std::endl;
	}
	adr1.close();
};

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "russian");
	std::string town;
	std::string strit;
	int house = 0;
	int apart = 0;
	std::ifstream adr("in.txt");
	int N = 0;
	adr >> N;
	Address* addr = new Address[N];
	for (int i = 0; i < N; i++)
	{
		adr >> town >> strit >> house >> apart;
		addr[i] = Address(town, strit, house, apart);
	}
	adr.close();
	sort(addr, N);
	out_adr(addr, N);
	del(addr, N);
}

