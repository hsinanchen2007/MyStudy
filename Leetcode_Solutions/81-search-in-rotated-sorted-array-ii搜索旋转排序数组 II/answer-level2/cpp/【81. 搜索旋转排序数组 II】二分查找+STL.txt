## 思路一：二分查找
### 代码
时间复杂度：O(logn)
```c++
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                while (left != mid && nums[left] == nums[mid]) {
                    ++left;
                }
                if (left == mid) {
                    ++left;
                    continue;
                }
            }
            if (nums[left] != nums[mid]) {
                if (nums[left] < nums[mid]) {
                    if (nums[left] <= target && target < nums[mid]) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                } else {
                    if (nums[mid] < target && target <= nums[right]) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }

            } else {
                if (nums[mid] < nums[right]) {
                    if (nums[mid] < target && target <= nums[right]) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                } else {
                    if (nums[left] <= target && target < nums[mid]) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
            }
        }
        return false;
    }
};
```
#### 简化代码
```c++
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            }
            //去重，和题33解法唯一不同点
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
               ++left, --right;
            } else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};
```

## 思路二：无序set
### 代码
unordered_set插入时间复杂度：O(logn)
```c++
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        unordered_set<int> uset(nums.begin(), nums.end());
        return uset.count(target) > 0;
    }
};
```



