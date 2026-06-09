### 解题思路
数学法：
![image.png](https://pic.leetcode-cn.com/6dea5196af1063ecde097ee5a67b9227433ffcf6c86960f7824cf5a6e0841de3-image.png)

### 代码

```python3
class Solution:
    def arrangeCoins(self, n: int) -> int:

        # 数学方法：n = (k+1)*k/2，经过数学推导，k = （8n+1）开根号减一再除以2
        return int(((8 * n + 1) ** 0.5 - 1) // 2)
        
        # if n == 0:
        #     return 0
        # if n == 1:
        #     return 1

        # for i in range(n):
        #     res = (i+1)*i // 2
        #     if res < n:
        #         continue
        #     elif res == n:
        #         return i
        #     else:
        #         return i-1
# 作者：powcai
```
```python3
class Solution:
    def arrangeCoins(self, n: int) -> int:  
        i = 1
        while n - i >= 0:
            n -= i
            i += 1
        return i - 1
```
