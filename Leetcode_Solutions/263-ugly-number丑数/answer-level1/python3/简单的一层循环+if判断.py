只要能除得的尽就除，不然就判断
```
while True:
            if num == 0:
                return False
            elif num == 1:
                return True
            elif num%2 == 0:
                num /= 2
            elif num%3 == 0:
                num /= 3
            elif num%5 == 0:
                num /= 5
            else :
                return False
```
