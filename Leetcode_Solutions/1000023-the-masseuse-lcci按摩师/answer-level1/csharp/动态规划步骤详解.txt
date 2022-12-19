### 解题思路
先考虑0预约和1预约，此时天数分别为0和nums[0]。2天预约则取最大值。
3~N天时，每天都比较一次“接预约”和“不接预约”两种情况的最优解。此时不考虑接下来的天数。
[接预约]
因为 今天接预约的情况下，昨天必然不接预约，那么昨天不在决策范围内。
所以 今天接预约的最优解 = 前天最优解 + 今天获得的收益
[不接预约]
因为 昨天的最优解必然大于等于前天的最优解。
又因为 不接预约，今天无收益。
所以 今天的不接预约的最优解 = 昨天的最优解

由上面两种情况可得：
今天的最优解 = Max(前天最优解 + 今天获得的收益, 昨天的最优解)。

不断地求最优解，直到最后一天，就能得到总体的最优解了。

两篇代码是同一个思路，区别是中间状态用int[nums.Length]存还是3个int存。

### 代码

```csharp
public class Solution {
    public int Massage(int[] nums) {
        switch (nums.Length)
            {
                case 0:
                    return 0;
                case 1:
                    return nums[0];
                default:
                    break;
            }
            int[] dp = new int[nums.Length];
            dp[0] = nums[0];
            dp[1] = Math.Max(nums[0], nums[1]);
            for (int i = 2; i < nums.Length; i++)
            {
                dp[i] = Math.Max(nums[i] + dp[i - 2], dp[i - 1]);
            }
            return dp[nums.Length - 1];
    }
}
```


```csharp
public class Solution {
    public int Massage(int[] nums) {
        switch (nums.Length)
            {
                case 0:
                    return 0;
                case 1:
                    return nums[0];
                default:
                    break;
            }
        
            int byDay = nums[0];
            int yDay = Math.Max(nums[0], nums[1]);
            int temp;
            for (int i = 2; i < nums.Length; i++)
            {
                if (nums[i] + byDay > yDay)
                {
                    temp = byDay;
                    byDay = yDay;
                    yDay = nums[i] + temp;
                }
                else
                {
                    byDay = yDay;
                }
            }
            return yDay;
    }
}
```