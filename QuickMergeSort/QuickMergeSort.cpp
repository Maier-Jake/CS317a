//	You will write two programs to sort arrays of strings. One version will implement the QuickSort, the
//	other will implement MergeSort.
//	You must use basic sequential arrays in your programming language (no library data structures such as
//	ArrayList or Vector). You must also your own sort code. Do not use any built-in libraries for sorting.
//	(Example: in C++, the declaration may look like string lines[N]; )
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	cout << "Hello World!\n";
	string iFileName;
	string oFileName;
	cout << "What is the NAME of the file you are reading FROM?" << endl;
	cin >> iFileName;
	cout << "What is the NAME of the file you are writing TO?" << endl;
	cin >> oFileName;

	ifstream inFile;
	inFile.open(iFileName);

	int lineCount = 0;

	string line;
	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			lineCount++;
		}
		inFile.close();
	}

	string* list;
	list = new string[lineCount];
	list[5] = "hey";


}