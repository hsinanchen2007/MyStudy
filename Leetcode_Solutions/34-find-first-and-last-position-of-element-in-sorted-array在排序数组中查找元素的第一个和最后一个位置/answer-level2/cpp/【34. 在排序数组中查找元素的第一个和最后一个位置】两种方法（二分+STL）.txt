## 思路一：二分查找

### 代码
时间复杂度：O(logn)
空间复杂度：O(1)
```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int left = searchLeft(nums, target);
        int right = searchRight(nums, target);
        return {left, right};
    }

    int searchLeft(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                if (mid == 0 || (mid - 1 >= 0 && nums[mid - 1] != target)) {
                    return mid;
                }
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    int searchRight(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                if (mid == nums.size() - 1 || (mid + 1 <= nums.size() - 1 && nums[mid + 1] != target)) {
                    return mid;
                }
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
```

### 另一种写法
```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int left = searchLeft(nums, target);
        int right = searchRight(nums, target);
        return {left, right};
    }

    int searchLeft(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                //一直向左找
                while (mid - 1 >= 0 && nums[mid - 1] == target) {
                    --mid;
                }
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    int searchRight(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                //一直向右找
                while (mid + 1 <= nums.size() - 1 && nums[mid + 1] == target) {
                    ++mid;
                }
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
```


## 思路二：STL
lower_bound：返回一个迭代器，指向键值 >= key的第一个元素
upper_bound：返回一个迭代器，指向键值 > key的第一个元素

### 代码
时间复杂度：O(logn)
空间复杂度：O(1)
```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);
        if (left == right) return {-1, -1};
        return {left - nums.begin(), right - nums.begin() - 1};
    }
};
```

