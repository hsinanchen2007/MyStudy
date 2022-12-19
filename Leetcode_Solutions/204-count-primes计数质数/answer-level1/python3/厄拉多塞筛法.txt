### 解题思路
厄拉多塞筛法，注意：
1. 判断是质数再筛选
2. range(start, end, i)，间隔的参数是放在第3个位置

### 代码

```python3
class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 2:
            return 0
        res = [1] * n
        res[0] = 0
        res[1] = 0
        # 0 1 2 3 4 5 6 7 8 9
        # 0 0 1 1 1 1 1 1 1 1
        # 0 0 1 1 0   0   0 0 
        for i in range(2, n):
            # i是质数，从 i * i（不从2开始是因为小于i的已经被筛过了）,
            # 间隔i,筛选出i的所有倍数
            if res[i] == 1:
                for j in range(i * i, n, i):
                    res[j] = 0
        return sum(res)
```