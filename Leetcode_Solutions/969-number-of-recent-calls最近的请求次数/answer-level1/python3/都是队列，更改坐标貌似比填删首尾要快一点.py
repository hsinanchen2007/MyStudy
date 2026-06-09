

大家的程序貌似都差不多，时间排名基本上也就这样了，最好时间大概接近90%这样。

相同的算法，只加减首尾坐标，比pop（0）大概快个几十ms这样。

二分查找我也试了，时间是三到五倍，想想也是，主要删除的对象都是在队首，二分查找效率自然会低不少。

```
class RecentCounter:

    def __init__(self):
        self.input=[]
        self.l=0
        self.r=0

    def ping(self, t: int) -> int:
        self.input+=[t]
        self.r+=1
        t-=3000
        while self.input[self.l]<t:
            self.l+=1
        return self.r-self.l
```
