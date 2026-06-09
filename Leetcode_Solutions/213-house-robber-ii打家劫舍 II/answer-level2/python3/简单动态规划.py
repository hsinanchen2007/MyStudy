### 解题思路
最简单的动态规划思路：
1. 长度为0，返回0
2. 长度为1，返回数值
3. 长度为2，返回max(list)
4. 长度大于等于3，共有三种起点可能：
    1.从0号位开始，无法取到最后一位
    2.从1号位开始，没有限制
    3.从2号位开始，没有限制
每次新加一个元素，都在dp[i-1]与dp[i-2]+new中选较大值

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums)
        row1 = [nums[0]]*n;
        row2 = [nums[1]]*n;
        row3 = [nums[2]]*n;
        for i in range(3, n):
            row1[i] = max(row1[i-1], row1[i-2]+nums[i-1]);
            row2[i] = max(row2[i-1], row2[i-2]+nums[i]);
            if i >= 4:
                row3[i] = max(row3[i-1], row3[i-2]+nums[i]);
        return max(row1[n-1], row2[n-1], row3[n-1])
```