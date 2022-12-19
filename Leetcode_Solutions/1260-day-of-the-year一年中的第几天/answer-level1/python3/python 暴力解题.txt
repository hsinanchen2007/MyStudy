100%  100%

```
class Solution:   
    def dayOfYear(self, date: str) -> int:
        day=0
        month_con={1:31,2:28,3:31,4:30,5:31,6:30,7:31,8:31,9:30,10:31,11:30,12:31}
        month_leap={1:31,2:29,3:31,4:30,5:31,6:30,7:31,8:31,9:30,10:31,11:30,12:31}
        if int(date[:4])%4==0 and int(date[:4])!=1900:
            for i in range(int(date[5:7])-1):
                day+=month_leap[i+1]
            day+=int(date[8:])
        else:
            for i in range(int(date[5:7])-1):
                day+=month_con[i+1]
            day+=int(date[8:])            
        return day
```
