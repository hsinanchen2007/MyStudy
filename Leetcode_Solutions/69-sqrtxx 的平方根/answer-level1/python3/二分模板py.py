### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    # 二分法
    def mySqrt(self, x: int) -> int:
        if x == 0:
            return 0
        start = 0
        end = x
        while start + 1 < end:
            #找 mid^2 <= x的LastPosition
            mid = start + (end-start)//2
            if mid**2 <= x:
                start = mid
            else:
                end = mid
        if end**2 <= x: return end
        else: return start
    #在题解中看到基本不等式方法
    # '''基本不等式(a+b)/2 >=√ab 推导自 (a-b)^2 >= 0，注意 a>0 且 b>0'''
    # def mySqrt(self, x: int) -> int:
    #     r = x
    #     while r*r > x:
    #         r = (r + x/r) // 2
    #     return int(r)
    # def mySqrt(self, x):
    #     """
    #     :type x: int
    #     :rtype: int
    #     """
    #     if x <= 1:
    #         return x
    #     r = x
    #     while r > x / r:
    #         r = (r + x / r) // 2
    #     return int(r)
```