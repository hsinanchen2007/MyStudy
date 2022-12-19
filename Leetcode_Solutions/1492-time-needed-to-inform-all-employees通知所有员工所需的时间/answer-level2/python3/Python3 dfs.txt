先用defaultdict存储edge， 然后dfs计算每个员工得到通知的时间，并存储在列表time中，最后对time求最大值。
```
class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        from collections import defaultdict
        time = [0] * n
        dic = defaultdict(list)
        for i in range(n):
            dic[manager[i]].append(i)
            
        def dfs(head, t, time):
            if dic[head]:
                t += informTime[head]
                for child in dic[head]:
                    time[child] = t
                    dfs(child, t, time)
                    
        dfs(headID, 0, time)
        return max(time)
```
