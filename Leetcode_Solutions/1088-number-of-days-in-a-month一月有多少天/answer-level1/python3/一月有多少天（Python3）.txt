#### 思路
首先判断该年是否非闰年，然后返回天数。
#### 代码
```
class Solution:
    def numberOfDays(self, Y: int, M: int) -> int:
        # 四年一闰、百年不闰、400年再闰
        def is_leapyear(year):
            if year % 400 == 0:
                return True
            if year % 100 == 0:
                return False
            if year % 4 == 0:
                return True
            return False
        if M == 1 or M == 3 or M == 5 or M == 7 or M == 8 or M == 10 or M == 12:
            return 31
        if M == 4 or M == 6 or M == 9 or M == 11:
            return 30
        if M == 2:
            if is_leapyear(Y) == True:
                return 29
            else:
                return 28
```
#### 复杂度分析
- 时间复杂度：O(1)
- 空间复杂度：O(1)
