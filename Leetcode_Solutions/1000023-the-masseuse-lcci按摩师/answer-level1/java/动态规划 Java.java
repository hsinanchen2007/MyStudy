### 解题思路
因为我们每一个得到的结果都依赖于之前得到的结果，所以我们采用动态规划的思路：

1. 考虑特殊情况：如果按摩师没有任何预约，那么返回时常为0
2. 考虑预约状态：任何一个预约都有两种状态，接受和拒绝，我们把接受第i个预约记作dp1，拒绝第i个预约记作dp0
3. 考虑总体时长：我们新定义两个变量为tdp0，和tdp1。 tdp0：第i个预约拒绝，前i个预约的总时长；tdp1：第i个预约接受，前i个预约的总时长。
4. 对于tdp0来说，如果第i个预约拒绝了，那么第i-1个预约既可以接受，也可以不接受所以我们记录下来的应该是`Math.max(dp0,dp1)`
5. 对于tdp1来说，如果你第i个预约接受了，那么第i-1个预约必定为拒绝，所以记录的时间应该是`dp0 + nums[i]`
6. 将tdp0和tdp1赋值回dp0和dp1，进行下一次的计算。
7. 返回dp0和dp1中较大的一个

### 代码

```java
class Solution {
    public int massage(int[] nums) {
        if(nums.length == 0)
            return 0;
        int dp0 = 0, dp1 = nums[0];
        for(int i = 1; i < nums.length; i++)
        {
            int tdp0 = (int)Math.max(dp0,dp1);
            int tdp1 = dp0 + nums[i];
            
            dp0 = tdp0;
            dp1 = tdp1;
        }
        return (int)Math.max(dp0,dp1);
    }
}
```