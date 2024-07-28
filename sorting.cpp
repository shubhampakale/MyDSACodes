#include <bits/stdc++.h>
using namespace std;

void swap(int &i ,int &j)
{
    int temp =i;
    i=j;
    j=temp;
} 

void selection_sort(vector<int> &v,int n )
{
    for(int i=0;i<n-1;i++)
    {
        int mini = i;
        for(int j=i+1;j<n;j++)
        {
            if(v[mini]>v[j])
            {
                swap(v[mini],v[j]);
            }
        }
    }
}

void bubble_sort(vector<int> &v ,int n)
{
    for(int i=n-1;i>0;i--)
    {
        int did_swap =0;
        for(int j=0;j<i;j++)
        if(v[j]>v[j+1])
        {
            swap(v[j],v[j+1]);
            did_swap=1;
        }
        if(did_swap==0)
        {
            break;
        }
    }
}

void insertion_sort(vector<int> &v ,int n)
{
    for(int i=1;i<n;i++)
    {
        int j = i;
        while(j>0 && v[j]<v[j-1])
        {
            swap(v[j],v[j-1]);
            j--;
        }
    }
}

void merge(vector<int> &v, int low, int mid, int high)
{
    vector<int> temp;

    //low..mid      starting low
    //mid+1..high   starting mid+1
    int left = low;
    int right = mid+1;

    while (left<=mid && right<=high) //Till elements are present on the left half or right half
    {
        if(v[left]<=v[right])
        {
            temp.push_back(v[left]);
            left++;
        }
        else
        {
            temp.push_back(v[right]);
            right++;
        }
    }

    while(left<=mid) //if elements are still left on Left half
    {
        temp.push_back(v[left]);
        left++;        
    }

    while(right<=high) //if elements are still left on Right half
    {
        temp.push_back(v[right]);
        right++;        
    }
    
    
    //putting back the temp vector to original one 
    for(int i=low;i<=high;i++)
    {
        v[i] = temp[i-low];
    }
    
}
void merge_sort(vector<int> &v ,int low ,int high)
{
    if(low == high) return;
    int mid = (low + high)/2;

    merge_sort(v,low,mid); 
    merge_sort(v,mid+1,high);
    merge(v,low,mid,high);
}

int partition(vector<int> &v,int low,int high)
{
    int pivot = v[low];
    int i = low;
    int j = high;

    while(i<j)
    {
        while(v[i]<=pivot && i<=high-1)
        {
            i++;    //finding 1st greater element than pivot
                    //from left to right 
        }

        while(v[j]>pivot && j>=low+1)
        {
            j--;    //finding 1st smaller element than pivot
                    //from right to left 
        }

        if(i<j) swap(v[i],v[j]);
    }
    swap(v[low],v[j]);
    return j;
}
void quick_sort(vector<int> &v ,int low ,int high)
{
    if(low<high)
    {
        int pIndex = partition(v,low,high);
        quick_sort(v,low,pIndex-1);
        quick_sort(v,pIndex+1,high);
    }
}


int main() {
    int n;
    cin>>n;

    vector<int> myVector(n);
   
    for(int i=0;i<n;i++) 
        cin>>myVector[i];
    
    //selection_sort(myVector,n);
    //bubble_sort(myVector,n);
    //insertion_sort(myVector,n);
    merge_sort(myVector,0,n-1);
    //quick_sort(myVector,0,n-1);

    for(int i=0;i<n;i++) 
    cout<<myVector[i]<<" ";
    
    return 0;

}