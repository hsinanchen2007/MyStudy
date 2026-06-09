### 解题思路
![QQ截图20200306155244.png](https://pic.leetcode-cn.com/cef449557df465fcde3fa129db191562ec27a7a2a5012699513910953bbe2a3c-QQ%E6%88%AA%E5%9B%BE20200306155244.png)

佛辣
### 代码

```python3
class Solution:
    def mySqrt(self, x: int) -> int:
        if x==1:
            return 1
        if x==0:
            return 0
        for i in range(0,x//2+1):
            if (i+1)*(i+1)>x:
                return i
```