```
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        return [int(i) for i in list(str(int("".join([str(i) for i in digits])) + 1))]
```
可惜效率不太好