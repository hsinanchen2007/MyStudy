### 代码

```python3
class Solution:
    def dayOfYear(self, date: str) -> int:
        def func(year):
            return False if year % 4 != 0 or (year % 100 == 0 and year % 400 != 0) else True

        set_ = {1:31, 2:29 if func(int(date[:4])) else 28, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11:30, 12:31}
        return sum([set_[i] for i in range(1, int(date[5:7]))]) + int(date[8:10])
        
```