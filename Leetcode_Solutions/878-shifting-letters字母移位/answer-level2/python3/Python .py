```
class Solution:
    def shiftingLetters(self, S: str, org_shifts) -> str:
        result = ""
        shifts = [sum(org_shifts)]
        for i in range(1, len(org_shifts)):
            shifts.append(shifts[i - 1] - org_shifts[i - 1])

        for i, c in enumerate(S):
            result += chr(ord('a') + ((ord(c) + shifts[i] - ord('a')) % 26))

        return result
```