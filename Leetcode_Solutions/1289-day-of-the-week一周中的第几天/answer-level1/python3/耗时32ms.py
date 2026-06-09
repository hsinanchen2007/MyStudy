```
class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        from datetime import datetime
        day_n1 = len(str(day))
        month_n1 = len(str(month))
        if day_n1 == 1:
            day = "0"+str(day)
        else:
            day = str(day)
        if month_n1 == 1:
            month = "0"+str(month)
        else:
            month = str(month)
        str1 = str(year)+month+day
        riqi = ["Monday","Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday"]
        taday = datetime.strptime(str1,"%Y%m%d").weekday()
        return(riqi[taday])
```
