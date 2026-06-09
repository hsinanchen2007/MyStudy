### 解题思路
if else 来做过滤器。
使用sort方法来输出符合题意的答案

### 代码

```python3
class Solution:
    def filterRestaurants(self, restaurants: List[List[int]], veganFriendly: int, maxPrice: int, maxDistance: int) -> List[int]:
        cand = []
        res_table ={}
        for res in restaurants:
            if veganFriendly == 0:
                if res[3] <= maxPrice and res[4] <= maxDistance:
                    cand.append([res[0],res[1]])
            else:
                if res[2] == 1 and res[3] <= maxPrice and res[4] <= maxDistance:
                    cand.append([res[0],res[1]])
        cand.sort(key=lambda x: (-x[1],-x[0]))
        return [c[0] for c in cand]
        
```