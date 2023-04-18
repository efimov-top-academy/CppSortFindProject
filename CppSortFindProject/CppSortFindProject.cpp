#include <iostream>

using namespace std;

void ArrayInit(int array[], int size)
{
    for (int i = 0; i < size; i++)
        array[i] = rand() % 100;
}

void ArrayPrint(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << "\n";
}

void ArraySortSelect(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int indexMin{ i };
        for (int j = i + 1; j < size; j++)
            if (array[j] < array[indexMin])
                indexMin = j;
        int temp = array[indexMin];
        array[indexMin] = array[i];
        array[i] = temp;
    }
}

void ArraySortBubble(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool isSort = true;
        for (int j = size - 1; j > i; j--)
            if (array[j] < array[j - 1])
            {
                isSort = false;
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        if (isSort)
            break;
    }
}

void ArraySortShacker(int array[], int size)
{
    int top{ 0 };
    int bottom{ size - 1 };
    bool isSort;

    while (top <= bottom)
    {
        isSort = true;
        for(int i = bottom; i > top; i--)
            if (array[i] < array[i - 1])
            {
                isSort = false;
                int temp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = temp;
            }
        if (isSort) break;
        top++;

        isSort = true;
        for(int i = top; i < bottom; i++)
            if (array[i] > array[i + 1])
            {
                isSort = false;
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        if (isSort) break;
        bottom--;
    }
}


void ArraySortInsert(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = array[i];
        int j;
        for (j = i; j > 0; j--)
            if (array[j - 1] > temp)
                array[j] = array[j - 1];
            else
                break;
        array[j] = temp;
    }
}

int ArrayFindLinear(int array[], int size, int key)
{
    for (int i = 0; i < size; i++)
        if (array[i] == key)
            return i;
    return -1;
}

int ArrayFindBinary(int array[], int size, int key)
{
    int left{ 0 };
    int right{ size - 1 };

    while (left <= right)
    {
        int indexMiddle = (right + left) / 2;
        if (array[indexMiddle] == key)
            return indexMiddle;
        if (key < array[indexMiddle])
            right = indexMiddle - 1;
        else
            left = indexMiddle + 1;
    }
    return -1;
}

void ArrayReverse(int array[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
}

void ArrayReversePart(int array[], int size, int indexBegin, int indexEnd);
//void ArrayReversePart(int array[], int size, int indexBegin, int subSize);
int ArrayMaxIndex(int array[], int size, int indexBegin, int indexEnd);

void ArraySortCake(int array[], int size);

void ArrayShiftLeft(int array[], int size, int shift)
{
    //shift = shift % size;
    shift %= size;

    for (int s = 0; s < shift; s++)
    {
        int temp = array[0];
        for (int i = 1; i < size; i++)
            array[i - 1] = array[i];
        array[size - 1] = temp;
    }
}

void ArrayShiftRight(int array[], int size, int shift)
{

}

int main()
{
    srand(time(nullptr));

    const int size{ 10 };
    int array[size];

    ArrayInit(array, size);
    ArrayPrint(array, size);

    //ArraySortSelect(array, size);
    //ArraySortBubble(array, size);
    //ArraySortInsert(array, size);
    //ArraySortShacker(array, size);

    //ArrayReverse(array, size);
    
    ArrayShiftLeft(array, size, 27);

    ArrayPrint(array, size);

    /*cout << "input key: ";
    int key;
    cin >> key;

    int result = ArrayFindBinary(array, size, key);

    if (result != -1)
        cout << "found key at " << result << " position\n";
    else
        cout << "key not found\n";*/

}
