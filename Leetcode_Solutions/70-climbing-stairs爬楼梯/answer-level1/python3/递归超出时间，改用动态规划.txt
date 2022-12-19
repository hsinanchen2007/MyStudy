### 解题思路
首先尝试了递归，然后在38次时候会报错超时，因为重复进行了太多的运算
所以改用自底而上的动态规划算法
### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        r = [None]*(n+1)  ## 创建一个代价数组，存储已经完成的计算结果
        r[0], r[1] = 1, 1  ## 数组需要一些初始
        for i in range(2, n+1):
            ans = 0
            ans = ans + r[i-1] + r[i-2]  ## 两步走战略，首先考虑迈出一步和迈出两步的两种情况
            r[i] = ans ## 将得到的答案存储，一边后面计算使用
        return r[n]

```