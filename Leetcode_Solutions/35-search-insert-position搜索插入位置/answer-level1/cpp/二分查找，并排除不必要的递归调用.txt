### 解题思路
二分查找，并排除不必要的递归调用

### 代码

```cpp
class Solution {
public:
    int findX(vector<int>& nums, int target, int left, int right){
        if( left <= right )
        {
            int mid = (left+right)/2;
            if( target == nums[mid] )
                return mid;
            else if( target < nums[mid] )
                return findX(nums, target, left, mid-1);
            else
                return findX(nums, target, mid+1, right);
        }
        return right+1;
    }
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if( len <= 0 ) return 0;
        // 边缘情况不必调用递归
        if( target < nums[0] ) 
            return 0;
        else if( target > nums[len-1] ) 
            return len;
        else 
            return findX(nums, target, 0, nums.size()-1);
    }
};
```