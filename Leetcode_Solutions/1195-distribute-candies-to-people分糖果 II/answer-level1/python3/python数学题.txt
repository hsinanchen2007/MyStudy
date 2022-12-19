```
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        l = [0 for x in range(num_people)]
        num = 1
        while candies > 0:
            a = num % num_people
            if candies >= num:
                l[a-1] += num
                candies -= num
                num += 1
            else:
                l[a-1] += candies
                candies = 0
        return l
```
