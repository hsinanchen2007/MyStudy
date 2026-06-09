## 思路一：顺序遍历
### 代码
时间复杂度：O(n)
```c++
class Solution {
public:
    int findMin(vector<int>& nums) {        
        int size = nums.size();
        for (int i = 1; i < size; ++i) {
            if (nums[i] < nums[i - 1]) {
                return nums[i];
            }
        }
        return nums[0];
    }
};
```

## 思路二：二分
### 代码
时间复杂度：O(logn)
```c++
class Solution {
public:
    int findMin(vector<int>& nums) {        
        int left = 0, right = (int)nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[left] <= nums[mid] && nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};
```
##### 另一种写法
```c++
class Solution {
public:
    int findMin(vector<int>& nums) {        
        int left = 0, right = (int)nums.size() - 1;
        while (left < right) {
            if (nums[left] < nums[right]) return nums[left];//没有旋转
            int mid = left + (right - left) / 2;
            if (nums[left] <= nums[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};
```


