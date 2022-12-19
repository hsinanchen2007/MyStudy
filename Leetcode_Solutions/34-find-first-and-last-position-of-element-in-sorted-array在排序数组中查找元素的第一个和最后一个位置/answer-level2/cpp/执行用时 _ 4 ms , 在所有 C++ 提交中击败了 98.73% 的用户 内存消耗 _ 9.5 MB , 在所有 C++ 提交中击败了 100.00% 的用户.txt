### 解题思路
学习了题解区大佬关于两端都闭以及左开右闭的两种写法，这里用C++写了一种两端都闭的情况。

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() < 1){
            return {-1, -1};
        }
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target){
                right = mid - 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
        }
        if(left >= nums.size() || nums[left] != target){
            return {-1, -1};
        }
        int lresult = left;
        
        left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                left = mid + 1;
            } 
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
        }
        if(right < 0 || nums[right] != target){
            return {-1, -1};
        }
        int rresult = right;
        return {lresult, rresult};
    }
};
```