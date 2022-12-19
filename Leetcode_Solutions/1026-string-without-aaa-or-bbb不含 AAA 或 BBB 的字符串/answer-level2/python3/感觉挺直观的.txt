```
class Solution:
    def strWithout3a3b(self, A: int, B: int) -> str:
        if A + B >= 3:
            if A > B:
                return "aab" + self.strWithout3a3b(A-2, B-1)
            elif A < B:
                return "bba" + self.strWithout3a3b(A-1, B-2)
            else:
                return "ab" * A
        else:
            return 'a' * A + 'b' * B
```