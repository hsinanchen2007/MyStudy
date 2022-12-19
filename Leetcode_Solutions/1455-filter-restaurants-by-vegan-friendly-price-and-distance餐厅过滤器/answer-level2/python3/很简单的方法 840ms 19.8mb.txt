### 解题思路
先筛选后排序

### 代码

```python3
class Solution:
    def filterRestaurants(self, restaurants: List[List[int]], veganFriendly: int, maxPrice: int, maxDistance: int) -> List[int]:
        
        for res in restaurants[:]:
            if (veganFriendly and res[2]!=veganFriendly) or res[3]>maxPrice or res[4]>maxDistance:
                index = restaurants.index(res)
                del restaurants[index]
        result = list()
        restaurants.sort(key=(lambda x:[x[1],x[0]]),reverse=True)
        for res in restaurants:
            result.append(res[0])
        return result
```