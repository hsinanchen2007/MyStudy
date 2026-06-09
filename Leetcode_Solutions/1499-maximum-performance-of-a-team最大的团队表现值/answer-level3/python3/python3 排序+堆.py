比赛的时候想到了需要将efficiency降序排列，
这个题目的Key在于对于给定的efficiency，只存在唯一最大值，所以总共只有n中方案！
纠结在了会有很多种方案，导致没有思路
1.efficiency 降序排列
2.维护长度为k的数列，保存speed，
**当长度到达k时每次我只需要弹出最小的speed即可
（或者压入之前判断一下，如果当前speed小于队列最小值，但是没有必要）
`import heapq
class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:

        '''
        比赛的时候想到了需要将efficiency降序排列，
        这个题目的Key在于对于给定的efficiency，只存在唯一最大值，所以总共只有n中方案！
        纠结在了会有很多种方案，导致没有思路
        1.efficiency 降序排列
        2.维护长度为k的数列，保存speed，
        **当长度到达k时每次我只需要弹出最小的speed即可
        （或者压入之前判断一下，如果当前speed小于队列最小值，但是没有必要）
        '''

        cache = sorted(map(list,zip(speed,efficiency)), key=lambda x: -x[1])

        dp = []
        s = 0
        ans = 0

        for x,y in cache:
            if len(dp)==k:
                t = heapq.heappop(dp)
                s -= t
            heapq.heappush(dp, x)
            s += x
            ans = max(ans,s*y)
        
        return ans%(10**9 + 7)`