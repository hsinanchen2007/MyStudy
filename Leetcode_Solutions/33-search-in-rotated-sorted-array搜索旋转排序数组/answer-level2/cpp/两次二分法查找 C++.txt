### 解题思路
第一次二分法查找旋转点，将原数组分割成两部分，确定搜索的目标位于前半部分还是在后半部分，再使用二分法在确定的区间内搜索目标。

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        if (nums.size() == 1) {
            return nums[0] == target ? 0 : -1;
        }

        int left = 0;
        int right = nums.size();

        if (nums[0] > nums[nums.size() - 1]) {
            int rotatedindex = searchRotatedIndex(nums);
            if (target > nums[0]) {
                right = rotatedindex;
            }
            else if (target == nums[0]) {
                return 0;
            }
            else if (target < nums[0]) {
                left = rotatedindex;
            }
        }

        int mid = left + (right - left) / 2;
        while (left < right) {
            if (target > nums[mid]) {
                left = mid + 1;
            }
            else if (target < nums[mid]) {
                right = mid;
            }
            else {
                return mid;
            }
            mid = left + (right - left) / 2;
        }
        return -1;
    }

    int searchRotatedIndex(vector<int>& nums) {
        int left = 0;
        int right = nums.size();
        int mid = right / 2;

        while (left < right) {
            if (nums[0] < nums[mid]) {
                left = mid;
            }
            else if (nums[0] > nums[mid]) {
                if (nums[mid - 1] > nums[mid]) {
                    return mid;
                }
                else {
                    right = mid;
                }
            }
            mid = left + (right - left) / 2;
        }
        return -1;
    }
};
```
![微信截图_20200406225027.png](https://pic.leetcode-cn.com/e7ff5a93ce539fae3497964122f7483f22e00a4a9a382bfe940c61dd7fd61380-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200406225027.png)
