### 解题思路
![QQ截图20200215170151.png](https://pic.leetcode-cn.com/025960d3e8f10181c6266607f9f93f11fc7878ea35c6f0ed85b58d150ad3eda4-QQ%E6%88%AA%E5%9B%BE20200215170151.png)


### 代码

```python3
import functools
class Solution:
    def dayOfYear(self, date: str) -> int:
        days_of_month=[31,28,31,30,31,30,31,31,30,31,30,31]
        days=0
        list_date=date.split("-")
        year=int(list_date[0])
        month=int(list_date[1])
        day=int(list_date[2])
        if month==1:
            return day
        if (year%4==0 and year%100!=0) or year%400==0:
            # 是闰年
            days+=functools.reduce(lambda x, y: x + y, days_of_month[0:month-1])
            if month>2:
                days+=1
            else:
                pass
            days+=day
        else:
            days += functools.reduce(lambda x, y: x + y, days_of_month[0:month-1])
            days += day
        return days
```