```
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        max_end, maps = 0, [0 for _ in range(1000)]
        
        for num, start, end in trips:
            maps[start] += num
            if maps[start] > capacity:
                return False
            maps[end] -= num
            max_end = max(max_end, end)

        for i in range(1, max_end):
            maps[i] += maps[i-1]
            if maps[i] > capacity:
                return False
        return True
```
