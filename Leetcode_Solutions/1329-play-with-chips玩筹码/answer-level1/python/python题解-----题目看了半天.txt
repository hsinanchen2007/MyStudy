```
class Solution(object):
    def minCostToMoveChips(self, chips):
        """
        :type chips: List[int]
        :rtype: int
        """
        l1 = 0
        l2 = 0
        for i in chips:
            if i%2 == 0:
                l1 += 1
            else:
                l2 += 1
        return min(l1,l2)
```
