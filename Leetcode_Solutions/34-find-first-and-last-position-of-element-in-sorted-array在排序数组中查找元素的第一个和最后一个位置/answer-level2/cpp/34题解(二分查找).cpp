### 解题思路
使用两次二分查找，类似于lower_bound和upper_bound
### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        int left = 0,right = nums.size();
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target)//找到的是第一个>=target的数，亦即是下边界
                left = mid + 1;
            else
                right = mid;
        }
        if(left == nums.size() || nums[left] != target) return res;
        res[0] = left;
        right = nums.size();
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] <= target)//找到的是第一个>target的数，那么left-1则是最后一个<=target的数，亦即是上边界
                left = mid + 1;
            else
                right = mid;
        }
        res[1] = left - 1;
        return res;
    }
};
```