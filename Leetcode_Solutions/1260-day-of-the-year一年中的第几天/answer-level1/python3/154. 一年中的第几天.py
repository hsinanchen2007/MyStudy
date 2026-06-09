### 解题思路
1处理数据2判断年份3得出天数

### 代码

```python3
class Solution:
    def dayOfYear(self, date: str) -> int:
        month1=[0,31,29,31,30,31,30,31,31,30,31,30,31]
        month2=[0,31,28,31,30,31,30,31,31,30,31,30,31]
        sum=0
        year,month,day=map(int,date.split('-'))
        if year%400==0 or year%4==0 and year%100!=0:
            for i in range(month):
                sum=month1[i]+sum
            sum=sum+day
        else:
            for i in range(month):
                sum=month2[i]+sum
            sum=sum+day
        return sum
            
```