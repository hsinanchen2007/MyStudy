```
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        car = [0]*1000
        for num, i, j in trips:
            for k in range(i,j):
                car[k] += num
        return max(car)<=capacity
```
