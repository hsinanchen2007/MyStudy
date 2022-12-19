### 解题思路
如下表：
length代表int数量（9），w代表一行可以放几个int（3）,y代表在第几行。
(1,1,1) y=0
(1,1,1) y=1
(1,1,1) y=2
### 代码

```python3
class Solution:
    def drawLine(self, length: int, w: int, x1: int, x2: int, y: int) -> List[int]:
        anw=[0]*length
        wid=w//32
        n1,m1=divmod(x1,32)
        n2,m2=divmod(x2,32)
        for i in range(wid*y+n1,wid*y+n2+1):
            anw[i]=-1
        if m1!=0:anw[wid*y+n1]+=1<<(32-m1)
        anw[wid*y+n2]-=(1<<(32-m2-1))-1
        return anw
```