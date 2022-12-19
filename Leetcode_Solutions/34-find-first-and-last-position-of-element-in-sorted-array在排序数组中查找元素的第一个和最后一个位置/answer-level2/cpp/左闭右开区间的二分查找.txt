### 解题思路
有几个注意的点

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)return {-1, -1};
        int left = left_bound(nums, target);
        int right = right_bound(nums, target);
        return {left, right};
    }
    int left_bound(vector<int> &nums, int target)
    {
        if(nums.size() == 0)return -1;
        int lo = 0, hi = nums.size();
        while(lo < hi)  //左闭右开区间
        {
            int mid = lo + (hi - lo)/2;
            if(target == nums[mid])
                hi = mid;  //继续往左侧搜索
            else if(target < nums[mid])
                hi = mid;  
            else if(target > nums[mid])
                lo = mid+1;
        }
        if(lo == nums.size())return -1;  //注意这里：target比所有数大，没有左侧边界
        return (nums[lo]==target ? lo : -1);  //如果nums[lo]的确是target，说明找到了左侧边界，否则返回-1
    }
    int right_bound(vector<int> &nums, int target)
    {
        if(nums.size() == 0)return -1;
        int lo = 0, hi = nums.size();
        while(lo < hi)
        {
            int mid = lo + (hi - lo)/2;
            if(target == nums[mid])
                lo = mid+1;  //继续往右侧搜索
            else if(target > nums[mid])
                lo = mid+1;
            else if(target < nums[mid])
                hi = mid;
        }
        if(lo == 0)return -1;  //注意这里：target比所有数小，没有右侧边界
        return (nums[lo-1]==target ? lo-1 : -1);
    }
};
```