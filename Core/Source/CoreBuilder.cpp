#include "pch.h"

int inputNumber;
string resultInRoman;
void ResolvingRomanNumeral(int number); //init function

auto main(int argc, char* argv[]) -> int
{

	// Challenge
	// Resolving Roman Numerals
	// I = 1, V = 5, X = 10, IX = 9, L = 50, C = 100, D = 500, M = 1000
	// Create a function that given a specific number return the correct Roman numeral
	// Sample input: 52
	// Sample output: LII

	cout << "Maximum number allowed: 1 to 3999 \n";
	cout << "Type: negative numbers (-1) to quit. \n";
	while (true)
	{
		cout << "Enter a Number: ";
		cin >> inputNumber;
		if (inputNumber < 0)
		{
			break;
		}
		else
		{
			if (inputNumber <= 0)
			{
				cout << "Invalid input. Please try again.\n";

				//thanks to stackoverflow.
				cin.clear();
				cin.ignore(numeric_limits<int>::max(), '\n');
			}
			else
			{
				if (inputNumber <= 3999)
				{
					ResolvingRomanNumeral(inputNumber);
				}
				else
				{
					cout << "You've reached the maximum number. Please try again.\n";
				}
			}
		}
	}
	return 0;
}

string GetRomanNumeral(int number)
{
	switch (number)
	{
		case 1: return string("I");
		case 5: return string("V");
		case 10: return string("X");
		case 50: return string("L");
		case 100: return string("C");
		case 500: return string("D");
		case 1000: return string("M");
		default: return string("0"); //incase there's an error
	}
}

string getIRoman(int number, int multiplier)
{
	//temporary string for I or 1
	string tmpString;
	for (int j = 0; j < number; j++)
	{
		tmpString += GetRomanNumeral(1 * multiplier);
	}
	return tmpString;
}

void ResolvingRomanNumeral(int number)
{
	int remainder;
	int sum;
	string romanNumeralsArray[4] = {};
	int arrCount = 0;
	int multiplier[4] = { 1,10,100,1000 };

	//convert int to string to get the length
	auto inputToString = std::to_string(number);

	for (int i = 0; i < inputToString.size(); i++) {
		remainder = number % 10; //get the remainder
		//4 or 9
		if (remainder == 4 || remainder == 9)
		{
			//to get the sum of the roman numerals
			sum = (remainder * multiplier[i]) + multiplier[i];
			//concat the string then push to array
			romanNumeralsArray[i] = GetRomanNumeral(multiplier[i]) + GetRomanNumeral(sum);
		}
		else
		{
			//1,2,3
			if (remainder >= 1 && remainder <= 3)
			{
				//push to array
				romanNumeralsArray[i] = getIRoman(remainder, multiplier[i]);
			}
			//6,7,8
			else if (remainder >= 6 && remainder <= 8)
			{
				//get 5, 50 or 500
				int fives = 5 * multiplier[i];
				//push to array
				romanNumeralsArray[i] = GetRomanNumeral(fives) + getIRoman((remainder - 5), multiplier[i]);
			}
			else
			{
				//5
				if (remainder > 0)
				{
					sum = remainder * multiplier[i];
					romanNumeralsArray[i] = GetRomanNumeral(sum);
				}
			}
		}
		//divide to get the remaining numbers excluding decimal coz int type
		number = number / 10;
	}

	// Q1 how can you pass the array in function with sizeof
	//get the length of the array
	size_t n = sizeof(romanNumeralsArray) / sizeof(romanNumeralsArray[0]);
	// iterate backward over the elements of an array
	for (int i = n - 1; i >= 0; i--) {
		cout << romanNumeralsArray[i];
	}
	cout << "\n";

	return;
}


