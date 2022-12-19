```
class Solution:
    def countBits(self, num: int) -> List[int]:
        count = []
        for i in range(num+1):
            count.append(bin(i).count("1"))
        return count
```
