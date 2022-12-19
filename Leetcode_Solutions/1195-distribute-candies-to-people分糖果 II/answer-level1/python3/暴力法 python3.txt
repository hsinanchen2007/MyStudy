```
class Solution:
    def distributeCandies(self, candies, num_people):
        result = [0]*num_people
        count = 1
        while candies >= count  :
            result[(count-1)%num_people] += count
            candies -= count
            count += 1
        result[(count-1)%num_people] += candies
        return result
```
