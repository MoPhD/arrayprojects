#include <iostream>
#include <vector>
#include<string>
using namespace std;

void swap_values(int& v1, int& v2);
void reverseString(string str, int size);
void resizeArray(int*&arr, int  currentSize, int newSize, int newElement);
int main()
{
	cout << "Question 1: " << endl;
	string str;
	cout << "Please enter a string:";
	cin >> str;
	reverseString(str, str.length());
	cout << endl;
	cout << endl << "Question 2: " << endl;
	int size = 5;
	int newElement;
	cout << "Please enter an integer:";
	cin >> newElement;
	int *arr = new int[5];
	for (int i = 0; i < size; i++) {
		arr[i] = i * 10;
		cout << "Current Array:" << arr[i] << endl;
	}
	size++;
	int newSize = size;
	//cout << "newSize: " << newSize << endl;
	resizeArray(arr, size, newSize, newElement);
	size = newSize;
	for (int i = 0; i < size; i++) {
		if (arr[i] > arr[newSize - 1])
			swap_values(arr[i], arr[newSize - 1]);
	}
	for (int i = 0; i <size; i++) {
		cout << "New Array:" << arr[i] << endl;
		//	cout << newSize;
	}

	cout << endl << "Question 3: " << endl;
	int *temp = new int[101];
	
	vector<int> v;
	cout << "Enter a list of student grades as integers.\n"
		<< "Place a negative number at the end.\n";
	int userInput, min, max;
	cin >> userInput;
	min = userInput;
	max = userInput;
	if (userInput <= min && userInput != -1)
		min = userInput;
	if (userInput >= max)
		max = userInput;
	while (userInput !=-1)
		
	{
		
		v.push_back(userInput);
		cin >> userInput;
		if (userInput <= min && userInput!=-1)
			min = userInput;
		if (userInput >= max)
			max = userInput;

	}
	
	int count = 0;
	
		
		for (int j = min; j <= max; j++) {
			for (int i = 0, count = 0; i <v.size(); i++) {
			if (v[i] == j) {
					count++;
					temp[j] = count;
					if (count > 1) {
						v.erase(v.begin() + i);
						i--;
					}
				}
		}
		
	}
		
		
		
		for (int i = 0; i < v.size(); i++) {
			for (int j = i+1; j < v.size(); j++) {
				if (v[i] > v[j])
					swap_values(v[i], v[j]);
			}
			cout << "Number of " << v[i] << "'s: " << temp[v[i]] << endl;
		}
		
		
		
	delete[]temp;

	return 0;
}
void swap_values(int& v1, int& v2)
{
	int temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
}
void reverseString(string str, int size)
{
	char *front = &str[0];
	char *rear = &str[str.length()];
	for (int i = 0; i < str.length(); i++)
		cout << *(front + i);
	char *temp;
	temp = rear;
	rear = front;
	front = temp;
	for (int i = str.length(); i >= 0; i--)
		cout << *(rear + i);
}
void resizeArray(int*&arr, int  currentSize, int newSize, int newElement)
{
	int *temp = new int[newSize];
	for (int i = 0; i < currentSize; i++)
		temp[i] = arr[i];
	delete[]arr;
	arr = temp;
	arr[newSize - 1] = newElement;

}