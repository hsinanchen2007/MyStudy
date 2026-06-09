### 解题思路
传统思路 按部就班即可，注意程序最后需要进行排序，如何评分相同时，需要id大的在前

### 代码

```python3
class Solution:
    def filterRestaurants(self, restaurants: List[List[int]], veganFriendly: int, maxPrice: int, maxDistance: int) -> List[int]:
        rest = []
        if not maxPrice:
            maxPrice = float('inf')
        if not maxDistance:
            maxDistance = float('inf')
        if veganFriendly:
            for item in restaurants:
                if item[2] and item[3] <= maxPrice and item[4] <= maxDistance:
                    rest.append(item)
        else:
            for item in restaurants:
                if item[3] <= maxPrice and item[4] <= maxDistance:
                    rest.append(item)
        rest.sort(key=lambda x:x[0], reverse=True)
        rest.sort(key=lambda x:x[1], reverse=True)
        id_list = [item[0] for item in rest]
        return id_list

```