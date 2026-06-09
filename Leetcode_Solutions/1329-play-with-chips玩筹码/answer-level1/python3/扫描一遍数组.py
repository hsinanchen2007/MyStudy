借鉴大神的思路：所有奇数位置上的砝码m,一起移动到某个奇数位置不需要任何代价，所有偶数位置上的砝码n一起移动到某个偶数位置上不需要代价。当这个奇数位置和偶数位置相邻，代价要么是奇数位置的砝码移动偶数位置上，代价为m,要么是偶数位置上的砝码移动到奇数位置上，代价为n，所以最小代价为两者的最小值。
```
class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        odd = 0
        even = 0
        for x in chips:
            if x % 2 == 0:
                odd += 1
            else:
                even += 1
        return min(odd, even)
```
