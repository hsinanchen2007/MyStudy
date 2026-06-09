### 解题思路

### 代码

```python3
class Solution:
    def mySqrt(self, x: int) -> int:
        # brute force
        # if x<=1:return x 
        # for i in range(1,x+1): # [1,n]
        #     if i*i > x: # 第一次超过 i*i / i**2 / i>x/i can prevent overflow
        #         return i-1 # 向下取整
        # binary search
        # if x<=1:return x
        # l,r = 1,x
        # while l<=r:
        #     m = l + (r-l)//2 # 偶数个：左中位数
        #     if m > x/m:
        #         r = m-1
        #     else:
        #         l = m+1
        # return r
        # Newton's method
        epsilon = 0
        x_i = x
        while x_i*x_i - x > epsilon:
            x_i = (x_i+x//x_i)//2 # 整除，损失一点
        return x_i
```