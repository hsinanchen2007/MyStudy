# 一次遍历
直接遍历数组，当出现nums[i]>nums[i+1]时，nums[i+1]即为最小值；若没有出现这种情况，那么nums[0]即为最小值。
```
int findMin(vector<int>& nums) {
        for (int i = 0; i < nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
                return nums[i + 1];
        }
        return nums[0];
    }
```
# 二分查找
数组若发生了旋转，则可分为两部分：前部分的任意元素都大于后部分的任意元素。nums[0]为前部分的最小值，我们可将二分查找方法中出现的中间值nums[m]与nums[0]比较。
若nums[m]>=nums[0]，则最小值必定在nums[m]的右边；
若nums[m]<nums[0]，则最小值在nums[m]的左边或者nums[m]就是最小值。
```
int findMin(vector<int>& nums) {
        if(nums.size()==1||nums[0]<nums.back())
            return nums[0];
        int l = 0, h = nums.size() - 1;
        while (l<h)
        {
            int m = (l + h) / 2;
            if(nums[m]>=nums[0])
            {
                l = m + 1;
            }
            else
            {
                h = m;
            }
        }
        return nums[h];
    }
```
这两部分代码提交后发现，直接遍历与二分查找所用时间相差无几，这是怎么回事。。。
