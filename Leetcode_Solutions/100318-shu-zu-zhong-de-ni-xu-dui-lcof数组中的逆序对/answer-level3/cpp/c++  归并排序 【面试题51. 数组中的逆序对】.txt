### 解题思路
归并排序添加一行代码即可， 见注释

### 代码

```cpp
class Solution {
public:
    int global_count = 0;
    int reversePairs(vector<int>& nums) {
        vector<int> copyarr(nums.size(), 0);
        merge_sort(nums, copyarr, 0, nums.size()-1);
        return global_count;
    }

    void merge_sort(vector<int>& nums, vector<int>& copyarr, int left, int right) {
        if (left >= right) return;
        int mid = (left+right) / 2;
        merge_sort(nums, copyarr, left, mid);
        merge_sort(nums, copyarr, mid+1, right);
        int i = left, j = mid+1, k = left;
        while (i <= mid && j <= right) {
            if (nums[j] < nums[i]) {
                copyarr[k++] = nums[j++];
                global_count += (mid-i+1);         // 关键点，也是归并排序添加的唯一一行代码。
            } else {
                copyarr[k++] = nums[i++];
            }
        }
        if (i <= mid) copy(nums.begin()+i, nums.begin()+mid+1, copyarr.begin()+k);
        if (j <= right) copy(nums.begin()+j, nums.begin()+right+1, copyarr.begin()+k);
        copy(copyarr.begin()+left, copyarr.begin()+right+1, nums.begin()+left);
    }
};
```