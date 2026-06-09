```
class Solution:
    def isPalindrome(self, x: int) -> bool:
        half_len = len(str(x)) // 2 + 1
        if x < 0 or (x % 10 == 0 and x != 0):
            return False
        elif x == int(str(x)[::-1]):
            return True
        else:
            return False
```
1. 按道理时间复杂度应该是O(n)，但不知为何速度也很快；
2. 折半对比反而不快。