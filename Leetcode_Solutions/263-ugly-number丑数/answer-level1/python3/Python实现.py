```
class Solution(object):
    def isUgly(self, num: int) -> bool:
        if num == 0:
            return False
        if num == 1:
            return True

        if num % 2 and num % 3 and num % 5:
            return False

        while not num % 2 or not num % 3 or not num % 5:
            if not num % 2:
                num //= 2
            if not num % 3:
                num //= 3
            if not num % 5:
                num //= 5

        if num == 1:
            return True
        else:
            return False

```
