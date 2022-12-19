```
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        left = 0
        right = 0
        m = 0
        num_of_0 = 0
        for i in range(len(seats)):
            if seats[i] == 0:
                left += 1
            else:
                break
        for i in range(len(seats)-1, -1, -1):
            if seats[i] == 0:
                right += 1
            else:
                break
        for i in range(len(seats)):
            if seats[i] == 0:
                num_of_0 += 1
            else:
                if num_of_0 > m:
                    m = num_of_0
                num_of_0 = 0
        if num_of_0 > m:
            m = num_of_0
        return max((m+1)//2, left, right)
```
