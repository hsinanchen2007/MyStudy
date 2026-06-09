### 解题思路
![image.png](https://pic.leetcode-cn.com/cf7f7618e3ab30ebaf85ae55196e2a2e4857791b393ae19a1ff7c8ec261cbde5-image.png)

### 代码

```cpp
class Solution {
public:
    int res=0;
    int reversePairs(vector<int>& nums) {
        MergeSort(nums, 0, nums.size()-1);
        return res;;
    }
    void MergeSort(vector<int>& arr,int l,int r)
    {
        if (l >= r)return;
        int mid = (l + r) / 2;
        MergeSort(arr, l, mid);
        MergeSort(arr, mid+1, r);
        count(arr, l, mid, mid + 1, r);
        merge(arr, l, mid, mid + 1, r);
    }
    void merge(vector<int>& arr, int l1, int r1, int l2, int r2)
    {
        vector<int> tmp(r2 - l1 + 1);
        int dx = 0,begin=l1;
        while (l1 <=r1 && l2 <= r2)
        {
            if (arr[l1] <= arr[l2])tmp[dx++] = arr[l1++];
            else tmp[dx++] = arr[l2++];
        }
        while (l1 <= r1)tmp[dx++] = arr[l1++];
        while (l2 <= r2)tmp[dx++] = arr[l2++];
        for (int val : tmp) arr[begin++] = val;
    }
    void count(vector<int>& arr, int l1, int r1, int l2, int r2)
    {
        int i=l1,j=l2;
        while(i<=r1&&j<=r2)
        {
            if(arr[i]>arr[j]) {res+=(r1-i+1);j++;}
            else i++;
        }
    }
};








```