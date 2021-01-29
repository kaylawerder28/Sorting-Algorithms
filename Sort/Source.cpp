#include <iostream>
using namespace std;

class SortingAlgo
{
public:
	void BubbleSort(int *A, int n)
	{
		for (int j = 0; j <= n - 1; j++)
		{
			for (int i = 0; i <= n - 2; i++)
			{
				if (A[i] > A[i + 1])
				{
					int temp = A[i];
					A[i] = A[i + 1];
					A[i + 1] = temp;
				}
			}
		}
	}
	void SelectionSort(int *A, int n)
	{
		for (int i = 0; i <= n - 2; i++)
		{
			int iMin = i;
			for (int j = i + 1; j <= n - 1; j++)
			{
				if (A[j] < A[iMin])
				{
					iMin = j;
				}
			}
			int temp = A[i];
			A[i] = A[iMin];
			A[iMin] = temp;
		}

	}
	void InsertionSort(int*A, int n)
	{
		for (int j = 1; j <= n - 1; j++)
		{
			int key = A[j];
			int i = j - 1;
			while ((i >= 0) && A[i] > key)// use a while because we are moving from right to left
			{
				A[i + 1] = A[i];
				i--;
			}
			A[i + 1] = key;
		}
	}
	void MergeSort(int *A, int n)
	{
		MergeSort(A, 0, n - 1);
	}
	void Merge(int *A, int p, int q, int r)
	{
		int n1 = (q - p) + 1;
		int n2 = r - q;
		int *L = new int[n1 + 1];
		int *R = new int[n2 + 1];
		for (int i = 0; i < n1; i++)
		{
			L[i] = A[p + i];
		}
		for (int j = 0; j < n2; j++)
		{
			R[j] = A[q + 1 + j];
		}
		L[n1] = 10000;
		R[n2] = 10000;
		int j = 0;
		int i = 0;
		for (int k = p; k <= r; k++)
		{
			if (L[i] <= R[j])
			{
				A[k] = L[i];
				i++;
			}
			else
			{
				A[k] = R[j];
				j++;
			}
		}
	}
	void MergeSort(int *A, int p, int r)
	{
		if (p < r)
		{
			int q = (p + r) / 2;
			cout << "Dividing Array " << p << " " << q << " " << r << endl;
			MergeSort(A, p, q);
			MergeSort(A, q + 1, r);
			Merge(A, p, q, r);
		}
	}
	int Partition(int *A, int start, int end)
	{
		int pivot = A[end];
		int p = start;
		for (int i = start; i < end; i++)
		{
			if (A[i] <= pivot)
			{
				int temp = A[i];
				A[i] = A[p];
				A[p] = temp;
				p++;
			}
		}
		int temp = A[end];
		A[end] = A[p];
		A[p] = temp;
		return p;
	}
	void QuickSort(int *A, int start, int end)
	{
		if (start < end) {
		int p = Partition(A, start, end);
		QuickSort(A, start, p - 1);
		QuickSort(A, p + 1, end);
		}
	}
	void QuickSort(int *A, int n)
	{
		QuickSort(A, 0, n - 1);
	}
	void PrintArray(int*A, int n)
	{
		for (int i = 0; i < n; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	int A[] = { 9,1,7,3,4,8 };
	SortingAlgo *algo = new SortingAlgo();
	algo->PrintArray(A, 6);
	//algo->BubbleSort(A, 6);
	//algo->SelectionSort(A, 6);
	//algo->InsertionSort(A, 6);
	//algo->MergeSort(A, 6);
	algo->QuickSort(A, 6);
	algo->PrintArray(A, 6);
	getchar();
}