两个排序是$O(MlogM+NlogN)$，双指针滑动算法是$O(M+N)$，二分查找是$O(MlogN)$，我这里实际运行起来差不多，最快都是$400ms+$，二分查找快个几毫秒而已，都不算快。

$O(M+N)$：

```py
class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort(); heaters.sort()
        m, n = len(houses), len(heaters)
        ans, r = 0, 0
        i, j= 0, 0
        while i < m and j < n:
            if houses[i] <= heaters[j]:
                r = heaters[j] - houses[i]
                i += 1
            elif j < n - 1:
                r = min(heaters[j + 1] - houses[i], houses[i] - heaters[j])
                if houses[i] < heaters[j + 1]:
                    i += 1
                else:
                    j += 1
            else:
                r = houses[i] - heaters[j]
                i += 1
            ans = max(ans, r)
        return ans
```

$O(MlogN)$:

```py
class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort(); heaters.sort()
        ans = 0
        for i in houses:
            j = bisect.bisect(heaters, i)
            r = float('inf')
            if i >= heaters[0]:
                r = min(r, i - heaters[j - 1])
            if i < heaters[-1]:
                r = min(r, heaters[j] - i)
            ans = max(ans, r)
        return ans
            
```
