以1900年3月1日作为参照计算时间。
除了2100是平年以外，别的只要看是否是4的倍数就行了。

```
class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        def getday(date):
            y,m,d=int(date[:4]),int(date[5:7]),int(date[-2:])
            if m>2:
                m-=3
            else:
                m+=9
                y-=1
            ml=[0,31,30,31,30,31,31,30,31,30,31,31]
            md=[0]
            for i in range(1,12):
                md.append(ml[i]+md[-1])
            l=d+md[m]+(y-1900)*365+(y-1900)//4
            if y==2100:
                l-=1
            return l
        return abs(getday(date1)-getday(date2))
```
另解，用库函数转换时间戳，除以86400

```
import time
class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        t1= int(time.mktime(time.strptime(date1,"%Y-%m-%d")))
        t2= int(time.mktime(time.strptime(date2,"%Y-%m-%d")))
        return abs(t1-t2)//86400
```
