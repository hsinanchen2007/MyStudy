因为看到是要求最长的连续递增的序列 就是在维护一段区间  就想到了双指针的方法， j为慢指针， i为快指针 一开始j 和i分别指向第一个和第二个数，如果nums[i]>nums[i-1] 就说明他是递增的，求出i到j的距离 并跟之前的距离取最大值。 如果不是递增的 那么慢指针j就跳到i的位置，距离还是取最大值，直到遍历结束。

```
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size(), res = 1;
        int i =0, j=0;
        for(i = 1; i < n; i ++)
        {
            if(nums[i] <= nums[i-1] )  j=i;
            res =max(res, i-j+1);
        }
        return res;
    }
};
```
