//Bubble Sort Implementation in Ascending Order

#include <iostream> 
using namespace std;

//Bubble sort Algorithm
void bubbleSort(int arr[], int n){
	bool flag = false; 
	for (int i=0; i<n-1;i++){ 
		for(int j = 0; j<n-i-1; j++){ 
			if(arr[j]>arr[j+1]){
				flag = true;
				swap(arr[j],arr[j+1]);
			}
		}
		if(flag==false)
			return;
	}
}
    
int main() 
{ 
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    bubbleSort(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}



//Selection Sort Implementation in Descending Order
#include <iostream> 
using namespace std;

void selectionSort(int arr[],int n)
{
    int i,j,min,temp;
    for(i=0;i<n;i++){
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]>arr[min]){
                min=j;
            }
        }
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        
    }
}

int main() 
{ 
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    selectionSort(arr,n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}



// Count Sort Implementation in Ascending Order

#include <iostream> 
using namespace std;

void countSort(int arr[],int n){
    int k = arr[0];
    for(int i=0; i<n; i++){
        k = max(k, arr[i]);
    }
    int count[k]={0};
    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }
    for(int i=1; i<=k; i++){
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1; i>=0; i--){
        output[--count[arr[i]]]=arr[i];
    }
    for(int i=0; i<n; i++){
        arr[i]=output[i];
    }
}
int main() 
{ 
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    countSort(arr,n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
