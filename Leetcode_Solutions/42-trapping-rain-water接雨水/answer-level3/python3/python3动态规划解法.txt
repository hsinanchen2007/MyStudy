### 解题思路
写个题解纪念一下第一道没看答案做出来的困难题，虽然时间和空间复杂度都不算好。

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) < 3: #长度超过3才能盛水
            return 0
        dp = [0 for i in range(len(height))]
        s = 2 #从第三个开始计算
        while s < len(height):
            if height[s] <= height[s - 1]: # 如果s高度比前一位s-1高度低，则不能盛水
                dp[s] = dp[s - 1]
            else:
                add = 0 # 如果s比s-1高度高，则向前寻找第一个高度高于前一位的方柱j，此时能盛的水是s-j-1*s-1高度与min(s,j)的差
                while True: # 如果j之前还存在k满足height[k]在height[j]和height[s]之间，那么还能继续盛水，令height[s-1]=height[j]，再重复之前的查找过程寻找新的j
                    old = height[s-1]
                    for j in range(s - 2, -1, -1):
                        if height[j] > height[s - 1]:
                            add += (min(height[j], height[s]) - height[s - 1]) * (s - 1 - j)
                            height[s - 1] = min(height[j], height[s])
                            break
                    if old == height[s-1]: # 如果找不到更多j，则跳出循环
                        break
                dp[s] = dp[s - 1] + add
            s += 1
        return dp[-1]
```