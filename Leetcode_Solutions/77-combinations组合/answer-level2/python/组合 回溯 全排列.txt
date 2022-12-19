### 解题思路

但很慢 744ms beat 17%

回溯法解决组合问题。和排序问题不同的是，在组合问题中元素的顺序不考虑，只需要从当前位置向后寻找。排序问题每次都需要从头寻找，需要用visited数组记录访问过的元素。

### 代码

```python3
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res, c = [], 0
        def solve(i, t, tmp, visited): # t代表了tmp的长度
            if t==k: res.append(tmp)
            visited[i] = 1
            for j in range(i, n+1): # 注意这里是从i开始遍历的! 因为i以前的所有情况已经枚举过了
                if not visited[j]:
                    solve(j, t+1, tmp+[j], visited)
            visited[i] = 0 # 状态重置! 很重要

        for i in range(1, n+1): # 这部分根本不需要!
            solve(i, 1, [i], [0]*(n+1))
        return res
```
精简了之后

```
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res, c = [], 0
        def solve(i, t, tmp, visited):
            if t==k: 
                res.append(tmp)
                return # 加了return要快一点! 
            visited[i] = 1
            for j in range(i, n+1):
                if not visited[j]:
                    solve(j, t+1, tmp+[j], visited)
            visited[i] = 0

        solve(0, 0, [], [0]*(n+1))
        return res
```

再优化一下 84ms
```
class Solution:
    def combine(self, n: int, k: int):
        res, c = [], 0
        def solve(i, t, tmp, visited):
            if t==k: 
                res.append(tmp)
                return
            visited[i] = 1
            for j in range(i, n-((k-1)-t)+1): # 主要改动在这里, 遍历的范围缩小了, n+1-(k-1)-len(tmp)之后的数肯定无法形成组合了, 因为就算加上之后所有的数组合的tmp长度也小于k
                if not visited[j]:
                    solve(j, t+1, tmp+[j], visited)
            visited[i] = 0

        solve(0, 0, [], [0]*(n+1))
        return res
```


很快的76ms

这个代码的思路是, 先生成[[1],[2],[3],[4]], 再生成[[1,2],[1,3],[1,4]] + [[2,3],[2,4]] + [[3,4]]
```
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        curr=[[]]
        candidates=list(range(1,n+1))
        remain=k-len(curr[0])
        while curr and remain:
            nxt=[]
            for sol in curr:
                val=0 if sol==[] else sol[-1]
                for i in candidates[val:n-remain+1]:
                    nxt.append(sol+[i])
            curr=nxt
            remain=k-len(curr[0])
        return curr
```

还可以用排列组合的的性质C(m,n)=C(m-1,n)+C(m-1,n-1)
```
class Solution(object):
    def combine(self, n, k):
        if k>n or k==0:
            return []
        if k==1:
            return [[i] for i in range(1,n+1)]
        if k==n:
            return [[i for i in range(1,n+1)]]
        
        answer=self.combine(n-1,k) # C(m-1,n)
        for item in self.combine(n-1,k-1): # C(m-1,n-1)
            item.append(n)
            answer.append(item)
        
        return answer
```