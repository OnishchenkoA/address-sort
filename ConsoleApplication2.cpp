#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

class address
{
private:
	std::string town;
	std::string strit;
	int house;
	int apart;
	std::string output_adress{};
public:
	address(std::string town, std::string strit, int house, int apart)
	{
		this->town = town;
		this->strit = strit;
		this->house = house;
		this->apart = apart;
	}

	std::string* get_town(address* address, int N)
	{
		std::string* town = new std::string[N]{};
		return town;
	}

	std::string get_output_address()
	{
		output_adress = town + " , " + strit + " , " + std::to_string(house) + " , " + std::to_string(apart);
		return output_adress;
	}

std::string* mass_addr(int N)
{
	std::string* addr = new std::string[N]{};
	return addr;
}

void del(std::string* addr, int N)
{
	delete[]addr;
	addr = NULL;
}

void sort(address* address, int N)
{
	for (int i = 0; i < N; i++)
		for (int j = i; j < N - 1; j++)
		{
			
			if (address[j].town > address[j + 1].town)
			{
				address temp = adress[j];
				address[j] = address[j + 1];
				address[j + 1] = temp;
			}
		}
}

void out_adr(std::string* addr, int N)
{
	std::ofstream adr1("out.txt");
	if (adr1.is_open())
	{
		adr1 << N << std::endl;
		for (int i = N; i > 0; i--)
		{
			adr1 << addr[i] << std::endl;

		}
	}
	else {
		std::cout << "Ошибка открытия файла!" << std::endl;
	}
	adr1.close();
}
};

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "russian");
	std::string town;
	std::string strit;
	int house = 0;
	int apart = 0;
	address adr2(town, strit, house, apart);
	std::ifstream adr("in.txt");
	int N = 0;
	adr >> N;
	std::string* addr = adr2.mass_addr(N);
	for (int i = 1; i <= N; i++)
	{
		adr >> town >> strit >> house >> apart;
		addr[i] = addr[town, strit, house, apart];
		addr[i] = adr2.get_output_address();
	}
	adr.close();
	adr2.sort(adr2.get_town(addr, N), N);
	adr2.out_adr(addr, N);
	adr2.del(addr, N);
}

