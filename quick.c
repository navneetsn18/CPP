#include<stdio.h>
#include<time.h>
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 
int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; 
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) 
	{ 
		if (arr[j] <= pivot) 
		{ 
			i++; 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		int pi = partition(arr, low, high); 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 
int main()
{
    int arr[10],n,i;
    double total_time;
    clock_t start, end;
    printf("\n Enter the number of elements: ");
    scanf("%d",&n);
    printf("\n Enter the array: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }   
    printf("\n The inserted array is: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    start = clock();
    quickSort(arr,0,n-1);
    end = clock();
    total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n The sorted array is: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n Quick Sort function took %f seconds to execute \n", total_time);
    return 0;    
}