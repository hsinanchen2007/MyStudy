### 解题思路
之前对他有点模糊看到其他牛人的解释终于把他吃下了

### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        if n<=2:
            return n
        d=1
        p=2
        fb=0
        for i in range(2,n):
            fb=d+p
            d=p
            p=fb
        return fb
```