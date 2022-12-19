### 解题思路
计算n以内的平方数有多少个就行了

### 代码

```python3
class Solution:
    def bulbSwitch(self, n: int) -> int:
        #统计每个开关切换了多少次
        #要判断一个开关最后是开的还是关的，需要判断 n+1 % (0~n)是否为0
        #只有平方数的因子数是奇数，因此计算n以内的平方数的个数就是答案
        res = 0
        i = 1
        while True:
            if i ** 2 > n:
                break
            res += 1
            i += 1
        return res
```