### 方法一：调用库
其实这道题是一道很好的题目，可以通过编写模块化代码锻炼自己的能力。但是既然出在周赛了，还是以第一题的形式出现，所以还是用库先过了再说吧~
### 代码
```python []
from datetime import datetime 
class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        date1 = datetime.strptime(date1,'%Y-%m-%d')
        date2 = datetime.strptime(date2,'%Y-%m-%d')
        res = abs((date1 - date2).days)
        return res
```
### 方法二：模块化定义函数，结构清晰
#### 算法
1. 首先让第一个日期在第二个日期前面；
2. 从第一个日期一天天递增，直到两个日期相同；
3. 注意考虑闰年和不同月份对天数的影响。
### 代码
```python []
class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        # 日期格式化
        date1 = date1.split('-')
        date2 = date2.split('-')
        year1, month1, day1 = int(date1[0]), int(date1[1]), int(date1[2])
        year2, month2, day2 = int(date2[0]), int(date2[1]), int(date2[2])

        num_days = 0
        # 第一个日期排在前面
        if not self.dateIsBefore(year1, month1, day1, year2, month2, day2):
            year1, year2 = year2, year1
            month1, month2 = month2, month1
            day1, day2 = day2, day1
        # 从第一个日期逐天递增
        while not self.equal_dates(year1, month1, day1, year2, month2, day2):
            year1, month1, day1 = self.nextDay(year1, month1, day1)
            num_days += 1
        return num_days

    def isLeapYear(self, year):
        """如果是闰年返回 True，否则返回 False"""
        if year % 4 == 0:
            if year % 100 == 0:
                if year % 400 == 0:
                    return True
                else:
                    return False
            else:
                return True
        else:
            return False


    def daysInMonth(self, year, month):
        """
        输入一个月，输出该月正确的天数。
        """
        if self.isLeapYear(year):
            days = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        else:
            days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        return days[month - 1]


    def nextDay(self, year, month, day):
        """判断下一天的日期"""
        if day < self.daysInMonth(year, month):
            return year, month, day + 1
        else:
            if month == 12:
                return year + 1, 1, 1
            else:
                return year, month + 1, 1


    def equal_dates(self, year1, month1, day1, year2, month2, day2):
        """ 检查两个日期是否相同 """
        return year1 == year2 and month1 == month2 and day1 == day2


    def dateIsBefore(self, year1, month1, day1, year2, month2, day2):
        """如果 year1-month1-day1 在 year2-month2-day2
        之前，返回 True，否则返回 False。"""
        if year1 < year2:
            return True
        if year1 == year2:
            if month1 < month2:
                return True
            if month1 == month2:
                return day1 < day2
        return False

```


