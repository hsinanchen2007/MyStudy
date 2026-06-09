### 解题思路
第一时间想到的思路是奇偶和，参考了评论区的大佬，找到了自己的问题，在条件的地方注意不要溢出，还有就是隔开的和大于奇数偶数和的情况，不是很明白
![S0LHWL34`XJHTGW_7Z)FC5B.png](https://pic.leetcode-cn.com/ad207e8303fe5b916b7ce8bbe1c3374f29f8c4829ed4da225963b024b625ec78-S0LHWL34%60XJHTGW_7Z\)FC5B.png)

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
        return 0;
        int sum0 = 0, sum1 = 0;
        int i=0;
        while(i<nums.size())
        {
            if(i % 2 == 0)
            {
                sum0 += nums[i];
                sum0 = max(sum0, sum1);
            }
            else
            {
                sum1 += nums[i];
                sum1 = max(sum0, sum1);
            }
            ++i;
        }
        return sum0>sum1?sum0:sum1;
    }
};
```