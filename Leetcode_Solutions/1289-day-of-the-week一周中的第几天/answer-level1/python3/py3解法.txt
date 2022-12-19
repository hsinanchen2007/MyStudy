```
import datetime
class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        week_day = [ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" ]
                
        anyday=datetime.datetime(year,month,day).strftime("%w")
        
        return week_day[int(anyday)]
```
