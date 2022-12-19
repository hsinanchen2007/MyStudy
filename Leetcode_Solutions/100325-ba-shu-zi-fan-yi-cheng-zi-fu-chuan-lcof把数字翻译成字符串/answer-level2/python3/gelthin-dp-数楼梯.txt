### 解题思路
参考题解[【把数字翻译成字符串】：回溯，动态规划](https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/solution/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-hui-su-dong-tai/)的数楼梯的思路

忘了特例 506 导致错误， 需要额外判断一下第一个字符是否是 '0'



### 代码

```python3
class Solution:
    def translateNum(self, num: int) -> int:
        num_l = list(str(num))
        if num_l == 0:
            return 0
        if num_l == 1:
            return 1
        DP = [0 for x in range(len(num_l)+1)]
        DP[0] = 1  #为了使 DP[2] = DP[1] + DP[0] 适应边界条件
        DP[1] = 1
        for i in range(2, len(num_l)+1):  # 特例 506
            if num_l[i-2]!='0' and 0<= int(num_l[i-2]+num_l[i-1])<=25:  ## 这里 i-1 代表第 i 个字符
                DP[i] = DP[i-1] + DP[i-2] ## 小心 i-2 溢出
            else:
                DP[i] = DP[i-1]
        return DP[len(num_l)]
```