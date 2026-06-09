### 解题思路
Sort an Array

### 代码

```cpp
class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {
        int n=(l+r)/2;
        int x = nums[n];  
        int i = l - 1, j = r + 1;
        while (i < j) {
            do i++; while (nums[i] < x);
            do j--; while (nums[j] > x);
            if (i < j) swap(nums[i], nums[j]);
        }
        return j;
    }
    
    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int pivot = partition(nums, l, r);
        quickSort(nums, l, pivot);
        quickSort(nums, pivot + 1, r);
    }
    
    vector<int> sortArray(vector<int>& nums) 
    {
        quickSort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};


```