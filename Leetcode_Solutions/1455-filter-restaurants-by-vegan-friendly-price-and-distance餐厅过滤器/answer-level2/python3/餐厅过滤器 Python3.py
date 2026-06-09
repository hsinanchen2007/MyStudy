### 解题思路
先按考虑`veganFriendly`，然后筛选就行了。最后按筛选结果拍序。注意先按 **rating** 排序，再按 **id** 排序。

### 代码

```python3
class Solution:
    def filterRestaurants(self, restaurants: List[List[int]], veganFriendly: int, maxPrice: int, maxDistance: int) -> List[int]:
        dic = {}
        for restaurant in restaurants:
            if veganFriendly == 0:
                if restaurant[3] <= maxPrice and restaurant[4] <= maxDistance:
                        dic[restaurant[0]] = restaurant[1]
            else:
                if restaurant[3] <= maxPrice and restaurant[4] <= maxDistance and restaurant[2] == 1:
                        dic[restaurant[0]] = restaurant[1]
        res = []
        # 按照 rating 从高到低排序。如果 rating 相同，那么按 id 从高到低排序。
        dic = sorted(dic.items(), key = lambda x:[x[1],x[0]],reverse=True)
        for i in dic:
            res.append(i[0])
        return res
```
### 复杂度分析
- 时间复杂度：$O(NlogN)$
- 空间复杂度：$O(N)$