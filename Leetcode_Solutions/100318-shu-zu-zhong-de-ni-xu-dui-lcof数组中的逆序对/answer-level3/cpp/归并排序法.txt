### 解题思路
归并排序法


### 代码

```cpp
class Solution {
public:
    int count = 0;
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size(), 0);
        mergeSort(nums, temp, 0, nums.size() - 1);
        return count;
    }

    void mergeSort(vector<int>& nums, vector<int>& temp, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = (left + right) / 2;
        mergeSort(nums, temp, left, mid);
        mergeSort(nums, temp, mid + 1, right);
        int l = left, r = mid + 1, tempIndex = left;
        while (l <= mid && r <= right) {
            if (nums[l] > nums[r]) {
                temp[tempIndex++] = nums[r++];
                count += (mid - l + 1);
            } else {
                temp[tempIndex++] = nums[l++];
            }
        }
        
        while (l <= mid) {
            temp[tempIndex++] = nums[l++];
        }
        while (r <= right) {
            temp[tempIndex++] = nums[r++];
        }
         while(left <= right){
            nums[left] = temp[left];
            left++;
        }
    }
};
```