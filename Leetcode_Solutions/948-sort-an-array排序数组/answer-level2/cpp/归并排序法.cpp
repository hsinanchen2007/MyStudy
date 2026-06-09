### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int>temp(nums.size(), 0);
        mergeSort(nums, temp, 0, nums.size() - 1);
        return nums;
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
        // 同步数组
        while (left <= right) {
            nums[left] = temp[left];
            left++;
        }
    }

};
```