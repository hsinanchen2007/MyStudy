```
class Solution:
    def distributeCandies(self, candies, num_people):
        disList = [0] * num_people
        i = 0
        res = candies

        while True:
            i += 1
            if res > i:
                disList[(i-1) % num_people] += i
                res = res - i
            else:
                disList[(i-1) % num_people] += res
                return disList
```
