### 解题思路
首先编写两个函数，一个用于判断是否是闰年，另一个用公共尺度衡量天数。
然后在主函数中进行日期推导。
最后得到目标天数是周几。

### 代码

```python3
class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        def isRunYear(year):
            return False if year % 4 != 0 or (year % 100 == 0 and year % 400 != 0) else True

        def getDay(day, month, year):
            months = {1:31, 2:29 if isRunYear(year) else 28, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11:30, 12:31}
            return day + sum([months[i] for i in range(1, month)]) + sum([366 if isRunYear(i) else 365 for i in range(1970, year)])

        days = {0:'Sunday', 1:'Monday', 2:'Tuesday', 3:'Wednesday', 4:'Thursday', 5:'Friday', 6:'Saturday'}
        temp1, temp2, ret = getDay(9, 3, 2020), getDay(day, month, year), 0
        if temp1 >= temp2:
            ret = ((temp1 - temp2) % 7 * -1 + 7 + 1) % 7 #因为2020年3月9日是周一，所以+1
        else:
            ret = ((temp2 - temp1) % 7 + 7 + 1) % 7
        return days[ret]
```