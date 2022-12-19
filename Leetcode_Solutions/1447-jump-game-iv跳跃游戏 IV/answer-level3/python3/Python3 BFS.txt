求最少次数，典型的 BFS 问题。

注意只处理一次值相同的元素，不能重复处理，否则会 TLE。

```
class Solution:
    def minJumps(self, arr: List[int]) -> int:
        d = collections.defaultdict(list)
        dis = [-1] * len(arr)
        
        for i, x in enumerate(arr):
            d[x].append(i)

        q = collections.deque()
        
        res = 0
        start = 0
        dis[start] = 0
        q.append(start)
        
        while q:
            for _ in range(len(q)):    
                pos = q.popleft()
                if pos == len(arr) - 1:
                    return res
                else:
                    if pos > 0:
                        if dis[pos - 1] < 0:
                            dis[pos-1] = res + 1
                            q.append(pos-1)
                    if dis[pos + 1] < 0:
                        dis[pos+1] = res + 1
                        q.append(pos+1)
                    x = arr[pos]
                    if x in d:
                        for y in d[x]:
                            if y != pos and dis[y] < 0:
                                dis[y] = res + 1
                                q.append(y)
                        d.pop(x)
            
            res += 1
        
```
