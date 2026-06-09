### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def filterRestaurants(self, restaurants, veganFriendly, maxPrice, maxDistance):
        """
        :type restaurants: List[List[int]]
        :type veganFriendly: int
        :type maxPrice: int
        :type maxDistance: int
        :rtype: List[int]
        """ 
        i = 0
        while i < len(restaurants):
            if veganFriendly and restaurants[i][2] == 0 or restaurants[i][3] > maxPrice or restaurants[i][4] > maxDistance:
                restaurants.pop(i)
            else: i += 1
        restaurants.sort(reverse=True, key=lambda x:(x[1],x[0]))
        res = []
        for i in restaurants:
            res.append(i[0])
        return res
```