### 解题思路
想象成是个圈，模拟来做，记住取余。

### 代码

```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        l = [i for i in range(n)]

        start=0                    #起始坐标
        while len(l) > 1:
            start+=(m-1)           #起始坐标开始数
            start %= len(l)        #但是由于是圈，所以会进行取余
            l.pop(start)           #删除这个数字 
        return l[0]
```