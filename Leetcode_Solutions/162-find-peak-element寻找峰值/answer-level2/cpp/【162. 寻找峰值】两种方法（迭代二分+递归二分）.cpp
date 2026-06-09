## 思路一：迭代二分
### 代码
时间复杂度：O(logn)
空间复杂度：O(1)
```c++
class Solution {
public:
    int findPeakElement(vector<int>& nums) {        
        if (nums.size() == 1) return 0;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```

## 思路二：递归二分
### 代码
时间复杂度：O(logn)
空间复杂度：O(logn)
```c++
class Solution {
public:
    int findPeakElement(vector<int>& nums) {        
        if (nums.size() == 1) return 0;
        return search(nums, 0, nums.size() - 1);
    }

    int search(vector<int> &nums, int left, int right) {
        if (left == right) {
            return left;
        }
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1]) {
            return search(nums, left, mid);
        } 
        return search(nums, mid + 1, right);        
    }
};
```

