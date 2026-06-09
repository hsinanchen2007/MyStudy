```
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quick_sort(arr,0,arr.size()-1,k);
        return vector(arr.begin(),arr.begin()+k);
    }
    void quick_sort(vector<int> &arr,int l,int r,int k)
    {
        if(l >= r) return;
        int i = l - 1, j = r + 1, x = arr[l + r >> 1];
        while(i < j)
        {
            do i++; while(arr[i] < x);
            do j--; while(arr[j] > x);
            if(i < j) swap(arr[i],arr[j]);
        }
        int sl = j - l + 1;
        if(sl >= k)
            quick_sort(arr,l,j,k);
        else quick_sort(arr,j+1,r,k-sl);
    }
};
```
>ps: 很奇怪 手写快排，比这个还快？？？？？
