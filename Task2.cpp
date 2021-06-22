// 1. Find length of an array

#include<iostream>
using namespace std;

int main(){

    int arr[]={1,4,8,9,3,2};

    int length_of_Array = sizeof(arr)/sizeof(arr[0]);//finding the size of array
    cout<<length_of_Array<<endl;
    return 0;
} 

// 2. Reverse the array

#include<iostream>
using namespace std;

int main(){
    int n,l=0,h;
    cin>>n;
    h=n-1;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    //Reversing the Array
    while(l<h){
        int temp=arr[l];
        arr[l]=arr[h];
        arr[h]=temp;
        l++;
        h--;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
} 


// 3. Find the maximum and minimum element in an array

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int max=0,min;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i]; 
    }

    for(int i=0; i<n; i++){
        if(max<arr[i]){
            max=arr[i];
        }
        if(min>arr[i]){
            min=arr[i];
        }
    }
cout<<"Maximum Element in Array :"<<max<<endl;
cout<<"Minimum Element in Array :"<<min<<endl;
return 0;
} 


// 4. Find the "Kth" max and min element of an array

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int max,min;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i]; 
    }
    sort(arr, arr + n);
    max = arr[n-k];
    min = arr[k-1];

    cout<<"Maximum Kth Element in the Array :"<<max<<endl;
    cout<<"Minimum Kth Element in the Array :"<<min<<endl;

    return 0;
}




// 4. Find the "Kth" max and min element of an array

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int max,min;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i]; 
    }
    sort(arr, arr + n);
    max = arr[n-k];
    min = arr[k-1];

    cout<<"Maximum Kth Element in the Array :"<<max<<endl;
    cout<<"Minimum Kth Element in the Array :"<<min<<endl;

    return 0;
}



// 6. Move all the negative elements to one side of the array

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int count = 0;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        if(arr[i]<0)
           {
               int temp = arr[i];
               arr[i] = arr[count];
               arr[count] = temp;
               count++; 
           }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
     return 0;
}




// 7. Find the Union and Intersection of the two sorted arrays.

#include<iostream>
using namespace std;

int printIntersection(int arr1[], int arr2[], int m, int n) 
{ 
  int i = 0, j = 0; 
  while (i < m && j < n) 
  { 
    if (arr1[i] < arr2[j]) 
       i++; 
    else if (arr2[j] < arr1[i]) 
       j++; 
    else 
    { 
       cout << arr2[j] << " "; 
       i++; 
       j++; 
    } 
  } 
} 

int printUnion(int arr1[], int arr2[], int m, int n) 
{ 
  int i = 0, j = 0; 
  while (i < m && j < n) 
  { 
    if (arr1[i] < arr2[j]) 
       cout << arr1[i++] << " "; 

    else if (arr2[j] < arr1[i]) 
       cout << arr2[j++] << " "; 

    else
    { 
       cout << arr2[j++] << " "; 
       i++; 
    } 
  } 

  while(i < m) 
     cout << arr1[i++] << " "; 

  while(j < n) 
    cout << arr2[j++] << " "; 
} 

int main(){
    int m;
    cin>>m;
    int arr1[m];
    for(int i=0;i<m;i++){
        cin>>arr1[i];
    }
    int n;
    cin>>n;
    int arr2[n];
    int count = 0;

    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }

    cout<<"Union elements in The Array :";
    printUnion(arr1, arr2, m, n);
    cout<<"Intersected elements in The Array :";
    printIntersection(arr1, arr2, m, n);

    return 0;
} 




// 8. Given an array of digits check if the array is palindrome or not.

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n],l=0,h=n-1;
    int count = 0;
    bool flag=0;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    while(l<h){
        if(arr[l]==arr[h]){
            flag=1;
            l++;
            h--;
        }
        else
            flag=0;
            break;
    }
    if(flag==1)
    cout<<"It is the Pallindrome Array";
    else
    cout<<"It is Not the Pallindrome Array";

    return 0;
} 
