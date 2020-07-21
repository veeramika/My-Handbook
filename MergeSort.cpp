#include<bits/stdc++.h>
using namespace std;
#define int long long
void _merge(vector<int> &v,int low, int mid, int high)
{
    vector<int> a1,a2;
    for(int i = low ; i <= high ; i++)
    {
        if(i<=mid)
            a1.push_back(v[i]);
        else a2.push_back(v[i]);
    }
    int n1 = a1.size();
    int n2 = a2.size();
    int i,j,k;
    i = j = 0;
    k = low;

    while(i<n1 && j<n2)
    {
        if(a1[i]<=a2[j])
            v[k++] = a1[i++];
        else v[k++] = a2[j++];
    }

    while(i<n1)
        v[k++]=a1[i++];
    while(j<n2)
        v[k++]=a2[j++];
}
void mergesort(vector<int> &v , int low, int high)
{
    if(low<high)
    {
    int mid = (low+high)/2;
    mergesort(v,low,mid);
    mergesort(v,mid+1,high);
    _merge(v,low,mid,high);
    }
}
int32_t main()
{
    int n,i,k;
    cin>>n;
    vector<int> v(n);
    for(i = 0 ; i < n ; i++)
        cin>>v[i];
    mergesort(v,0,n-1);
    cout<<"After sorting using MERGESORT => ";
    for(auto i : v)
        cout<<i<<" ";
    return 0;
}
