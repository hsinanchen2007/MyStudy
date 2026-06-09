## 思路一：简单遍历
### 代码
时间复杂度：O(n)
```c++
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int c = 0;
        for (auto num : nums) {
            if (num == target) {
                ++c;
            }
        }
        return c > nums.size() / 2 ? true : false;
    }
};
```

## 思路二：二分法
分别找到最左侧和最右侧目标数的下标位置，然后根据下标求出目标数个数，最后判断是否超过一半。
**注意：没有找到元素情况**
### 代码
时间复杂度：O(logn)
```c++
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int size = nums.size();
        int L = findLeft(nums, target);
        int R = findRight(nums, target);
        if (L == -1 && R == -1) {
            return false;
        }
        return (R - L + 1) > size / 2 ? true : false;
    }
    
    int findLeft(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;            
            if (nums[mid] == target) {
                if (mid - 1 >= l && nums[mid-1] == target) {//判断是否为最左侧
                    r = mid - 1;
                } else {
                    return mid;
                }
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
    
    int findRight(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                if (mid + 1 <= r && nums[mid+1] == target) {
                    l = mid + 1;
                } else {
                    return mid;
                }
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};
```

