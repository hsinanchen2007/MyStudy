```cpp
class Solution {
private:
    int count = 0;

    void mergeSort(vector<int> & nums, int l, int mid, int r) { // 合并两个有序数组
        int len = r - l + 1;
        vector<int> tmp(len, 0);
        int left = l;
        int right = mid + 1;
        int i = 0;
        while (left <= mid && right <= r) {
            if (nums[left] > nums[right]) {
                count += mid - left + 1;  //相比归并排序只加了这一句
                tmp[i++] = nums[right++];
            }
            else 
                tmp[i++] = nums[left++];
        }
        
        while (left <= mid)
            tmp[i++] = nums[left++];

        while (right <= r)
            tmp[i++] = nums[right++];
        
        for (int i = 0; i < len; i++)
            nums[l+i] = tmp[i];

    }

    void mSort(vector<int> & nums, int l, int r) {
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        
        mSort(nums, l, mid);   // 左半边排好序
        mSort(nums, mid + 1, r);   // 右半边排好序
        mergeSort(nums, l, mid, r);  // 合并两个有序数组
    }


public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) 
            return 0;
        mSort(nums, 0, n-1);
        return count;
    }
};
```