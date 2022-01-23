#include <iostream>

using namespace std;

void nullifyAroundOne(int someArray[], int length, int constLength);
void printArray(int myArray[], int length);

int main()
{
    setlocale(LC_ALL, "russian");

    int exampleArray[] = { 1,1,6,4,3,1,61,1,6,6,1,6,3,1,3,1 };
    int LENGTH = (sizeof(exampleArray) / sizeof(*exampleArray)) - 1;

    cout << "Исходный массив:" << endl;
    printArray(exampleArray, LENGTH);

    nullifyAroundOne(exampleArray, LENGTH, LENGTH);

    cout << "Измененный массив:" << endl;
    printArray(exampleArray, LENGTH);
}

void nullifyAroundOne(int myArray[], int length, int constLength)
{
    const int ABSOLUTE_LENGTH = constLength;
    int i = length;

    if (myArray[i - 1] != 1)
    {
        if (i - 1 != -1)
        {
            myArray[i - 1] = 0;
        }
    }
    if (myArray[i + 1] != 1)
    {
        if (i + 1 <= ABSOLUTE_LENGTH)
        {
            myArray[i + 1] = 0;
        }
    }

    if (i >= 0)
    {
        i -= 1;
        nullifyAroundOne(myArray, i, ABSOLUTE_LENGTH);
    }
}

void printArray(int myArray[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << myArray[i] << "|";
    }
    cout << endl;
}