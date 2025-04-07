#include<iostream>
using namespace std;
int arr[] = { 3,1,0,2,5,4};
void swap1(int*c,int*b){
    int temp=*b;
    *b=*c; 
	*c=temp;
}
int partition1(int arr[], int l, int h)
{
	int i=l;
	int j=h;
	int pivot=arr[l];
	for(;i<j;)
	{

		do
		{
			i++;
		}while(arr[i]<=pivot);

		do
		{
			j--;
		}while(arr[j]>pivot);

		if (i < j)
		{
			swap1(&arr[i],&arr[j]);
			for(int q=0;q<h;q++)
				cout<<arr[q]<<" ";
			cout<<'\n';
		}

	}


	swap1(&arr[l],& arr[j]);
	for(int q=0;q<h;q++)
		cout<<arr[q]<<" ";
	cout<<'\n';
	return j;
}

void quickSort1(int arr[], int l, int h)
{

	if (l < h) {
		int piv = partition1(arr, l, h);
		quickSort1(arr, l, piv);
		quickSort1(arr, piv + 1, h);
	}

}



int partition2(int arr[], int iBegin, int jEnd) {
	int i = iBegin;
	int j = jEnd;
	int pivLoc = i;
	while (true)
	{
		while (arr[pivLoc] <= arr[j] && pivLoc != j)
		{
			j--;
		}
		if (pivLoc == j)
			break;
		else if (arr[pivLoc] > arr[j])
		{
			swap(arr[j], arr[pivLoc]);
			pivLoc = j;
		}

		while (arr[pivLoc] >= arr[i] && pivLoc != i)
		{
			i++;
		}
		if (pivLoc == i)
			break;
		else if (arr[pivLoc] < arr[i])
		{
			swap(arr[i], arr[pivLoc]);
			pivLoc = i;
		}
	}
	return pivLoc;
}


void quickSort2(int arr[], int l, int h)
{

	if (l < h) {
		int piv = partition2(arr, l, h);
		quickSort2(arr, l, piv - 1);
		quickSort2(arr, piv + 1, h);
	}

}


int main()
{

	int n = sizeof(arr) / sizeof(arr[0]);

	int a[2]={1,2};
	//swap1(a+0,a+1);
	//cout<<a[0]<<a[1];
		for (int i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}
	    cout<<'\n';
		quickSort1(arr, 0, n );
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}

	return 0;
}
