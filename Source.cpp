// Patrick Callahan
// Cis 1202
// 12/05/2021


#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;


//class definitions
class invalidCharacterExcpeption{};

class invalidRangeException{};

class caseConversionException{};



char character(char start, int offset)
{
	int startingValue = int(start);

	int target = startingValue + offset;
	try {

		if (startingValue < 65 || (startingValue > 90 && startingValue < 97) || startingValue > 122)
		{
			throw invalidCharacterExcpeption();
		}
		else if (target < 65 || (target > 90 && target < 97) || target > 122)
		{
			throw invalidRangeException();
		}
		else if ((target >= 65 && target <= 90 && startingValue >= 95 && startingValue <= 122) || (target >= 95 && target <= 122 && startingValue >= 65 && startingValue <= 90))
		{
			throw caseConversionException();
		}
	}

	catch (invalidCharacterExcpeption exception1)
	{
		cout << "Invalid Character Exception " << endl;
		return ' ';
	}

	catch (invalidRangeException exception2)
	{
		cout << "Invalid Range Exception " << endl;
		return ' ';
	}

	catch (caseConversionException exception3)
	{
		cout << "Cannot make case changes from upper to lowercase  " << endl;
		return ' ';
	}

	return char(target);
}

int main() {

	cout << character('a', 1) << endl;
	cout << character('a', -1) << endl;
	cout << character('Z', -1) << endl;
	cout << character('?', 5) << endl;
	cout << character('A', 32) << endl;

	system("pause");
	return 0;
}