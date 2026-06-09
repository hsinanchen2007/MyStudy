![image.png](https://pic.leetcode-cn.com/c35b87606e5a532e934a5d176ed56eb7805a801c77881cf3d73840e21279dea2-image.png)


```
from typing import List
class Solution:
    def filterRestaurants(self, restaurants: List[List[int]], veganFriendly: int, maxPrice: int, maxDistance: int) -> List[int]:
        l = sorted([(-rating, -id, id) for id, rating, veg, price, dis in restaurants if (not (veganFriendly and not veg)) and price <= maxPrice and dis <= maxDistance])
        return [x[2] for x in l]
```
