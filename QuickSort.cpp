#include<bits/stdc++.h>
using namespace std;
#define int long long
int _partition(vector<int> &v,int left,int right)
{
    //Finding the correct position of rightmost element
    int pi = right;
    int i = left-1;

//initially------------------------------
    /// index : -1 0 1 2 3 4 5 ... n
 /// pointers :  i j ..............pi
 //---------------------------------------

    for(int j = left ; j < right ; j++)
    {
        if(v[j]<=v[pi])
        {
            swap(v[++i],v[j]);
        }
    }
    swap(v[++i],v[pi]);
    return i;
}
void quicksort(vector<int> &v,int left,int right)
{
    if(left<right) ///imp condition
    {
    int pi = _partition(v,left,right);
    quicksort(v,left,pi-1);
    quicksort(v,pi+1,right);
    }
}
int32_t main()
{
    int n,i,k;
    cin>>n;
    vector<int> v(n);
    for(i = 0 ; i < n ; i++)
        cin>>v[i];
    quicksort(v,0,n-1);
    cout<<"After sorting using QUICKSORT => ";
    for(auto i : v)
        cout<<i<<" ";
    return 0;
}
