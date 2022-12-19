### 解题思路
此处撰写解题思路
对于排序的数组可以使用二分查找，此题中一个排序的数组旋转导致数组中可能有两个递增的序列，所以找到那个转折点，最多进行两次二分查找就可以啦
### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }
        // 找到转折点，进行两次二分查找
        int povit = cross(nums);
        if (povit == -1) {
            return binSearch(nums, 0, n-1, target);
        } else {
            int left = binSearch(nums, 0, povit-1, target);
            if (left != -1) {
                return left;
            }

            return binSearch(nums, povit, n-1, target);
        }
    }

    int binSearch(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = (low+high)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return -1;
    }
    int cross(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low < high) {
            int mid = (low + high) / 2;
            if (mid > 0) {
                if (nums[mid - 1] > nums[mid]) {
                    return mid;
                }
            }
            if (mid < high) {
                if (nums[mid] > nums[mid+1]) {
                    return mid + 1;
                }
            }

            if (nums[mid] >= nums[low]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};
```