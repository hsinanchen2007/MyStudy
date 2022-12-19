### 解题思路
利用二分查找搜索离house最近的供暖器

### 代码

```python
class Solution(object):
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        houses.sort(), heaters.sort()
        n = len(heaters)
        min_radius = []
        for house in houses:
            radius = float('inf')
            left, right = 0, n-1
            while left <= right:
                mid = (left + right) // 2
                if house == heaters[mid]:
                    radius = 0
                    break
                elif house < heaters[mid]:
                    radius = min(radius, heaters[mid] - house)
                    right = mid - 1
                elif house > heaters[mid]:
                    radius = min(radius, house - heaters[mid])
                    left = mid + 1
            min_radius.append(radius)
        return max(min_radius)
```