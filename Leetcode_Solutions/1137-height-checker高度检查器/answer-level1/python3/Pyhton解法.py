先按照非递减的方式排好队，然后与原队伍比较，到底有多少个人没站对位置


```
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        nonDec = sorted(heights)
        diff = [i for i in list(map(lambda x, y: x - y, heights, nonDec)) if i != 0 ]
        return len(diff)
```