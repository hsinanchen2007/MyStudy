
内存占用很少，但是时间有些长。咋整？
![捕获.PNG](https://pic.leetcode-cn.com/2db6a91462eca188eb2a396db2d53fb57b7f5a7f48f9f27cfb9583c13b9849d4-%E6%8D%95%E8%8E%B7.PNG)


```
    class Solution:
    def filterRestaurants(self, restaurants: List[List[int]], veganFriendly: int, maxPrice: int, maxDistance: int) -> List[int]:
        restaurants = sorted(restaurants, key=lambda x: (x[:][1], x[:][0]), reverse=True)
        restaurants = restaurants if not veganFriendly else list(filter(lambda x: x[2] == 1, restaurants))
        return [rest[0] for rest in restaurants if rest[3] <= maxPrice and rest[4] <= maxDistance]
```


