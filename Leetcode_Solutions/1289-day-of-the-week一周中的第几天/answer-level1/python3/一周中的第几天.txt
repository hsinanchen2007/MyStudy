### 解题思路
计算某天和1979.1.1之间的天数，对7取模；

计算天数需要考虑：
1. 是否闰年
2. 二月多少天
3. 每个月30天还是31天

### 代码

```python3
class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
     
        # 原作者：saltingshelby
        # 判断是否为闰年
        def isLeapYear(year):
            return (year % 4 == 0 and year % 100 != 0) or year % 400 == 0

        # 注意，index从Sunday开始,这样保证索引1是周一
        calendar = ['Sunday', 'Monday', 'Tuesday', \
                    'Wednesday', 'Thursday', 'Friday', 'Saturday']

        month_days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

        if isLeapYear(year):
            # 闰年2月29天
            month_days[1] = 29

        year_days = [0] * (year - 1970)

        for i in range(1971, year):
            year_days[i - 1971] = 366 if isLeapYear(i) else 365

        # 1971-1-1 周五
        # 假如'1971-1-1'为周一， 那么对于1971-1-29，29 % 7 = 1，那么29号就是周一
        # 周二的话，就要加1，周五的话，就要加4
        count_days = sum(year_days) + sum(month_days[:month - 1]) + day + 4

        return calendar[count_days % 7]




        # # 判断是否为闰年
        # def isLeapYear(year):
        #     if year % 400 == 0:
        #         return True
        #     elif year % 100 == 0:
        #         return False
        #     elif year % 4 == 0:
        #         return True
        #     return False

        # # 判断一个月有多少天
        # def daysInMonth(year, month):
        #     if month == 1 or month == 3 or month == 5 or month == 7 \
        #             or month == 8 or month == 10 or month == 12:
        #         return 31
        #     else:
        #         if month == 2:
        #             if isLeapYear(year):
        #                 return 29
        #             else:
        #                 return 28
        #         return 30

        # # 判断下一天的日期
        # def nextDay(year, month, day):
        #     if day < daysInMonth(year, month):  # 2015.3.4 -> 2015.3.5
        #         return year, month, day + 1
        #     else:
        #         if month == 12:  # 2015.12.31 -> 2016.1.1
        #             return year + 1, 1, 1
        #         else:  # 2015.5.31 -> 2015.6.1
        #             return year, month + 1, 1

        # # 判断是否为曾经的日期
        # def dateIsBefore(year1, month1, day1, year2, month2, day2):
        #     if year1 < year2:
        #         return True
        #     if year1 == year2:
        #         if month1 < month2:
        #             return True
        #         if month1 == month2:
        #             return day1 < day2
        #     return False

        # # 判断日期之间的天数
        # def daysBetweenDates(year1, month1, day1, year2, month2, day2):
        #     days = 0
        #     while dateIsBefore(year1, month1, day1, year2, month2, day2):
        #         days += 1
        #         year1, month1, day1 = nextDay(year1, month1, day1)
        #     return days

        # # 判断为星期几
        # dic = {0: 'Sunday', 1: 'Monday', 2: 'Tuesday', 3: 'Wednesday',
        #        4: 'Thursday', 5: 'Friday', 6: 'Saturday'}
        # # 1971.1.1是星期五，通过给定日期与该日期的天数确定星期几
        # days = daysBetweenDates(1971, 1, 1, year, month, day)
        # return dic[(days + 5) % 7]


```