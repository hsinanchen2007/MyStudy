### Problem-solving Idea
Change the given number to a string first, and reverse it second.

### Code

```python3
class Solution:
    def reverse(self, x: int) -> int:
        if x == 0:
            return 0
        elif x > 0:
            if int(str(x)[::-1]) <= pow(2, 31):
                return int(str(x)[::-1])
            else:
                return 0
        else:
            if - int(str(-x)[::-1]) >= - pow(2, 31):
                return - int(str(-x)[::-1])
            else:
                return 0
```