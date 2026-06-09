一定程度上借用贪心思想，想象一下，想让较小值和最大，就需要尽量把大数凑到一起，这样保证其中的较小值也是大数

其他人题解中已有证明，不再赘述

因此可将数组排序，之后相邻两个一对，这样可以保证大数尽量集中

这样的话，所求的和值就是从第0项开始，隔一项加一项

代码：
```
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int len = nums.size() >> 1;
        int* p = &nums[0];
        sort(p, p + (len << 1));
        int ans = 0;
        for(int i = 0 ; i < len ; i++)
            ans = ans + p[i << 1];
        return ans;
    }
};
```


