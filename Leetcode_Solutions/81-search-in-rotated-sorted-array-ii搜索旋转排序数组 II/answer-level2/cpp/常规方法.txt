方法一：暴力遍历，无难度
方法二：二分查找
极端情况[2,1,1,2,2,,2,2,2,2]
此时left,mid,right均相等，在原来基础上分开讨论，没有特别好的解决方法，暴力++；
```
bool Solution::serch(vector<int>& nums, int target)
{
    int lo = 0, hi = nums.size() - 1, mid = 0;
    while (lo < hi)
    {
        mid = (lo + hi) / 2;
        if (nums[lo] == target || nums[hi] == target || nums[mid] == target) return true;
        //常规二分
        if (nums[lo] < nums[mid])
        {
            if (nums[lo] < target && target < nums[mid])
            {
                ++lo;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
                --hi;
            }
        }
        else if (nums[mid] < nums[hi])
        {
            if (nums[mid] < target && target < nums[hi])
            {
                lo = mid + 1;
                --hi;
            }
            else
            {
                ++lo;
                hi = mid - 1;
            }
        }
        //如果出现nums[lo]=nums[mid]或者nums[mid]=nums[hi]情况，暴力去重
        else
        {
            //去重
            while (lo != hi && nums[lo] == nums[mid]) ++lo;
            while (lo != hi && nums[mid] == nums[hi]) --hi;
            //++lo; --hi;
        }
    }
    //first == end情况，防止空数组访问越界，直接判断返回
    return (lo == hi && nums[lo] == target)?ture:false;
}
```
