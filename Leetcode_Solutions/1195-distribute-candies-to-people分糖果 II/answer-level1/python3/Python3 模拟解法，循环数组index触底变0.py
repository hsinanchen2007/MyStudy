```
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        res = [0] * num_people
        cur = 1
        i = 0
        while candies > 0:
            given = min(cur, candies)
            res[i] += given
            cur += 1
            candies -= given
            if i == num_people - 1:
                i = 0
            else:
                i += 1
        return res

```
