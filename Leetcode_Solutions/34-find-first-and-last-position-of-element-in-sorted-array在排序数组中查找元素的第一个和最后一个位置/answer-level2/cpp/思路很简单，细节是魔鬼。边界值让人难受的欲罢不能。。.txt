### 解题思路
参考评论区大佬的。。。哎。边界值让人头痛死。

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if((nums.size() == 0) || (nums.size() == 1 && nums[0] != target))
            return vector<int>{-1,-1};
        vector<int> result{-1,-1};
        int left = 0 , right = nums.size() - 1;
        int mid = left + (right - left) / 2;
        while(left < right)
        {
            mid = left + (right - left) / 2;
            if(nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
            
        }
        if(nums[left] != target)
            return result;
        result[0] = left;

        left = 0;
        right = nums.size();
        mid = left + (right - left) / 2;
        while(left < right)
        {
            mid = left + (right - left) / 2;
            if(nums[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        if(nums[left - 1] != target)
            return result;
        result[1] = left - 1;
    
    return result;
    }
};
```