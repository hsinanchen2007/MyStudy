
```
def heightChecker(self, heights: List[int]) -> int:
    a = sorted(heights)
    n = 0
    for i in range(len(a)):
        if a[i] ^ heights[i] != 0:
            n += 1
    return n
```
