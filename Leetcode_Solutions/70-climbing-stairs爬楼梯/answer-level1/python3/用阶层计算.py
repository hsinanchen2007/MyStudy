### 解题思路
可以发现：
1，1，1，1，1，1，1，1  C88种
2，1，1，1，1，1，1     C76种
2，2，1，1，1，1        C64种
2，2，2，1，1，         C52种
2，2，2，2              C30种

故对n
有Cnn + C(n-1)(n-2)...C(n-n/2)(n-n)
### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        sums = 0
        for i in range(n,(n+1)//2-1,-1):
            sums += xxx(i)/(xxx(n)*xxx(i-n))
            n -= 2
        return int(sums)

def xxx(s):     #计算阶层
    x = 1
    for i in range(1,1+s):
        x *= i
    return x
```