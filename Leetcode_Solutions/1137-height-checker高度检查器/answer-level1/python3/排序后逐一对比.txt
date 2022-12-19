这道题直接把给定的数组排序，然后统计排序后的数组跟原数组对应位置数字不相同的个数即可。
```Python
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        tmp = heights.copy()
        heights.sort()
        res = 0
        for i in range(len(heights)):
            if tmp[i] != heights[i]:
                res += 1
        return res
```