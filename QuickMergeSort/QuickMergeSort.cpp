//	You will write two programs to sort arrays of strings. One version will implement the QuickSort, the
//	other will implement MergeSort.
//	You must use basic sequential arrays in your programming language (no library data structures such as
//	ArrayList or Vector). You must also your own sort code. Do not use any built-in libraries for sorting.
//	(Example: in C++, the declaration may look like string lines[N]; )
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void Merge(string left[], int leftSize, string right[], int rightSize, string arr[])
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < leftSize && j < rightSize)
	{
		if (left[i] <= right[j])
		{
			arr[k] = left[i++];
		}
		else
		{
			arr[k] = right[j++];
		}
		k++;
	}
	if (i == leftSize)
	{
		//copy right[j..rightSize-1] to arr[k..leftSize+rightSize-1]
		while (j < rightSize)
		{
			arr[k++] = right[j++];
		}
	}
	else
	{
		//copy left[i..leftSize-1] to arr[k..leftSize+rightSize-1]
		while (i < leftSize)
		{
			arr[k++] = left[i++];
		}
	}
}
void MergeSort(string l[], const int &size)
{
	string* left;
	string* right;
	if (size > 1)
	{
		if (size % 2 == 0)
		{
			left = new string[(size / 2)];
			right = new string[(size / 2)];
			for (int i = 0; i < (size / 2); i++)
			{
				left[i] = l[i];
			}
			for (int i = (size / 2); i < size; i++)
			{
				right[i-(size/2)] = l[i];
			}
			MergeSort(left, (size / 2));
			MergeSort(right, (size / 2));
			Merge(left, size/2, right, size/2, l);
		}
		else
		{
			left = new string[(size / 2)];
			right = new string[(size / 2)+1];
			for (int i = 0; i < (size / 2); i++)
			{
				left[i] = l[i];
			}
			for (int i = (size / 2); i < size; i++)
			{
				right[i - (size / 2)] = l[i];
			}
			MergeSort(left, (size / 2));
			MergeSort(right, (size / 2)+1);
			Merge(left, size/2, right, (size/2)+1, l);
		}
		
	}
}

int HoarePartition(string arr[], const int& size)
{
	string p = arr[0];
	int i = 0;

}

void QuickSort()
{

}
int main()
{
	cout << "Hello World!\n";
	string inFileName;
	string outFileName;
	cout << "What is the NAME of the file you are reading FROM?" << endl;
	cin >> inFileName;
	cout << "What is the NAME of the file you are writing TO?" << endl;
	cin >> outFileName;

	ifstream inFile;
	inFile.open(inFileName);

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
	inFile.open(inFileName);
	if (inFile.is_open())
	{
		int count = 0;
		while (getline(inFile, line))
		{
			list[count++] = line;
		}
		inFile.close();
	}

	//sort array here.
	MergeSort(list, lineCount);

	//print out to file.
	ofstream outFile;
	outFile.open(outFileName);
	if (outFile.is_open())
	{
		for (int i = 0; i < lineCount; i++)
		{
			outFile << list[i] << endl;
		}
	}

	return 0;
}