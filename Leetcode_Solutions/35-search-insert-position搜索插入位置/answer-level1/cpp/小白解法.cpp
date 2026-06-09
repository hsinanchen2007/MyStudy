使用二分法的前提的数组需要有顺序排列。
关键是定义好左边右边和中间指向。
难点是中间值结果的判定。
```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1 ;
        int insert = 0;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(mid == right && nums[right] != target)
            {
                if(nums[right] > target)
                {
                    return right;
                }
                else 
                {
                    return right + 1;
                }
            }
            if(nums[mid] > target)
            {
                right = mid;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else 
            {
                return mid;
            }
        }
        return left;
    }
};
```
