/**
 * @author Dustin Gordon 
 */

#include <iostream>
using namespace std;
  
/**
 * Merges two sorted sub-arrays of A[].
 * First sorted sub-array is A[l..m].
 * Second sorted sub-array is A[m+1..r].
 */
void merge(int Array[], int left, int middle, int right)
{
    int i, j, n;
    int split1 = middle - left + 1;
    int split2 =  right - middle;
    int leftHalf[split1];
    int rightHalf[split2];

    for (i = 0; i < split1; i++)
    {
        leftHalf[i] = Array[left + i];
    }

    for (j = 0; j < split2; j++)
    {
        rightHalf[j] = Array[middle + 1+ j];
    }

    i = 0;
    j = 0;
    n = left;

    while (i < split1 && j < split2)
    {
        if (leftHalf[i] <= rightHalf[j])
        {
            Array[n] = leftHalf[i];
            i++;
        }
        else
        {
            Array[n] = rightHalf[j];
            j++;
        }
        n++;
    }

    while (i < split1)
    {
        Array[n] = leftHalf[i];
        i++;
        n++;
    }

    while (j < split2)
    {
        Array[n] = rightHalf[j];
        j++;
        n++;
    }

} 

/**
 * Uses mergeSort to sort sub-array A[l..r]
 * l is for left index and r is right index of the
 * sub-array of A[] to be sorted.
 */
void mergeSort(int Array[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left ) / 2;

        mergeSort(Array, left, middle);
        mergeSort(Array, middle + 1, right);

        merge(Array, left, middle, right);
    }
} 
  

int main() 
{ 
    cout << "Please enter the length (number of elements) of the input array: ";
	int n;
	cin >> n;
	
	if(n <= 0)
	{
		cout << "Illegal input array length!" << endl;
		return 0;
	}
	
	int* A = new int [n];
	
	cout << "Please enter each element in the array" << endl; 
	cout << "(each element must be an integer within the range of int type)." << endl;
	for(int i = 0; i < n; i++)
	{
		cout << "A[" << i << "] = ";
		cin >> A[i];
	}
  
    cout << "Given array A[] is: "; 
	for(int i = 0; i < n-1; i++)
    {
        cout << A[i] << ",";
    }
	cout << A[n-1] << endl;

    mergeSort(A, 0, n-1); 
  
    cout << "After merge sort, sorted array A[] is: "; 
	for(int i = 0; i < n-1; i++)
    {
        cout << A[i] << ",";
    }
	cout << A[n-1] << endl;
	
	delete [] A;
    return 0; 
} 