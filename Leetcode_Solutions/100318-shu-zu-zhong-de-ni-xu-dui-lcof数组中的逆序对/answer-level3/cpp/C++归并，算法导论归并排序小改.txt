归并排序的左边数组要是有一个元素比右边元素大，那这个左边元素以及其后面的所有数字都有相对于这个右边元素的逆序对。

```cpp
class Solution {
public:
int ans = 0;
int _merge(vector<int> &A, int l, int mid, int r)
{
    vector<int> L;
    vector<int> R;
    int ret =0;
    for(int i =l ;i < mid;i ++)
        L.push_back(A[i]);
    for(int i = mid;i < r;i ++)
        R.push_back(A[i]);
    int i = 0, j = 0;
    L.push_back(INT_MAX);
    R.push_back(INT_MAX);
    for(int k = l;k < r;k ++)
    {
        if(L[i]<=R[j])
        {
            A[k] = L[i++];
        }else
        {
            A[k] = R[j++];
            ret += L.size()-i-1;
        }
    }
    return ret;
}
//[l,r)
void merge_sort(vector<int> &A, int l, int r)
{
    if(l < r-1)
    {
        int mid = (l+r)/2;
        merge_sort(A,l,mid);
        merge_sort(A, mid, r);
        ans +=_merge(A,l,mid,r);
    }
    return;
}
    int reversePairs(vector<int>& nums) {
        for(int i =0 ;i < nums.size();i ++)
        nums[i]--;
    merge_sort(nums, 0, nums.size());
    return ans;
    }
};
```

