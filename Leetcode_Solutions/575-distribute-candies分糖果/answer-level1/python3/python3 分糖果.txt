数组长度为2n，妹妹拿n颗糖，如果糖的种类数x>=n,则妹妹拿到n种糖果；反之，妹妹拿到x种糖果。x = len(set(candies))
```
class Solution:
    def distributeCandies(self, candies: List[int]) -> int:
        return min(len(candies)//2 , len(set(candies)))
```
