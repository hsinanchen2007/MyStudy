### 解题思路
存储最小丑数，依次向上取，o(n)复杂度
暴力的话 会超时

### 代码

```python3
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        if n <= 1:
            return n
        res = [1] * n
        i2,i3,i5 =0,0,0
        for i in range(1,n):
            res[i] = min(res[i2]*2,min(res[i3]*3,res[i5]*5))
            if res[i] == res[i2] * 2:
                i2 += 1
            if res[i] == res[i3] * 3:
                i3 += 1
            if res[i] == res[i5] * 5:
                i5 += 1
        return res[-1]
        
```