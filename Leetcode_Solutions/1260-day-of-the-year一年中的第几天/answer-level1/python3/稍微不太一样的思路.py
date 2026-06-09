```
def dayOfYear(self, date):
    [y, m, d] = map(int, date.split("-"))
    is_leap = int((y%100 == 0 and y%400==0) or (y%100 != 0 and y % 4 == 0))
    f = lambda m, y : 30 + int((m % 2 == 1 and m < 8) or (m%2 == 0 and m>7)) - (int(m==2)*2  - int(m == 2 and is_leap))
    return sum( f(x, y) for x in range(1, m)) + d 
```

