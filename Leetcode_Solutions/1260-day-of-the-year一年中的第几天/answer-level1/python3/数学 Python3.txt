**思路：**

先处理字符串，提取年（year）、月（month）和日（day）。如果月份为第一月，那么直接返回 `day` 即可。如果月份为第二月，那么直接返回 `day + 31`。如果月份大于二月，那么先判断是否为闰年，如果为闰年，结果就加 29，如果不为闰年，则结果加28。然后遍历所有小于该月的月份，统计大月（31天）和小月（30）天的个数，最后相加输出答案。


**代码：**
```python
class Solution:
    def ordinalOfDate(self, date: str) -> int:
        month_of_days31 = [1, 3, 5, 7, 8, 10, 12]
        month_of_days30 = [4, 6, 9, 11]
        feb_month = 2
        year, month, day = map(int, date.split('-'))
        
        def is_leap_year(year):
            if year % 4 == 0 and year % 100 != 0 or year % 400 == 0:
                return True
            return False
        
        if month == 1:
            return day

        if month == 2:
            return day + 31

        days_of_31_num = 0
        days_of_30_num = 0
        
        # 31天月份数
        for days_of_31 in month_of_days31:
            if days_of_31 < month:
                days_of_31_num += 1
            else:
                break

        # 30天月份数
        for days_of_30 in month_of_days30:
            if days_of_30 < month:
                days_of_30_num += 1
            else:
                break

        return days_of_31_num * 31 + days_of_30_num * 30 + (29 if is_leap_year(year) else 28) + day
```

