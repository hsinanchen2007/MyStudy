### 解题思路
唉   脑子水分太多

### 代码

```python3
class Solution:
    def mySqrt(self, x: int) -> int:

        if x == 0:
            res = 0
        elif x < 4:
            res = 1
        elif x < 9:
            res = 2
        else:
            i = x //2
            maxnum = x//2
            minnum = 2
            while not(i**2 <= x and (i + 1)**2 >= x):
                    if i**2 > x:
                        maxnum = i
                        i = (i + minnum)//2
                    elif (i+1)**2 < x:
                        minnum = i
                        i = (i + maxnum)//2
                    if (i+1)**2 ==x:
                        res = i +1
                    else: res = i

        return res
```