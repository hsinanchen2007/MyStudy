```
class Solution:
    def dayOfYear(self, date: str) -> int:
        list1 = date.split("-")
        list1[1] = int(list1[1])
        list1[2] = int(list1[2])
        import datetime
        date1 = datetime.date(int(list1[0]),list1[1],list1[2])
        return(int(date1.strftime('%j')))
        
```
