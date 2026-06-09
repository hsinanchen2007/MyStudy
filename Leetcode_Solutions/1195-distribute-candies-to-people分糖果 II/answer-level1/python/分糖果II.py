```
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        res = [0]*num_people
        i = 0
        candy_num = 1
        while candies != 0:
            if candy_num < candies or candy_num == candies:
                res[i] += candy_num
                candies -= candy_num
                candy_num += 1
                if i<num_people-1:
                    i += 1
                else:
                    i = 0
            else:
                res[i] += candies
                break
        return res          
```