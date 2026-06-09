```
import datetime
class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        week_day_dict = {
            0:"Sunday",
            1:"Monday",
            2:"Tuesday",
            3:"Wednesday",
            4:"Thursday",
            5: "Friday",
            6:"Saturday"
        }
                
        anyday=datetime.datetime(year,month,day).strftime("%w")
        
        return week_day_dict[int(anyday)]
```
