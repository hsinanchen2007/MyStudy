【分析】Greedy
    根据题意，可对n道菜按满意度递增排序，显然满意度最高的菜为负数时直接返回0(此时只要安排上一道菜，满意度必 < 0，所以只能一道菜都不安排)；然后依次自右向左判断安排第i~(n - 1)道菜的满意度，最大化即可。
    时间复杂度O(n^2), 空间复杂度O(1)。
```
class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        n, res = len(satisfaction), 0
        
        satisfaction.sort()
        if satisfaction[n - 1] < 0:
            return 0
        for i in range(n - 1, -1, -1):
            curSum, curP = 0, 1
            for j in range(i, n):
                curSum += (satisfaction[j] * curP)
                curP += 1
            res = max(res, curSum)
        return res
```
