### 解题思路
没有使用常规DP，采用自顶向下的回溯法解决问题。
函数find的d,i，代表，第d天，从i任务开始，往左做。尝试所有可能情况。
函数内部，第d天的任务区间为j in (i,n-d)+find(d-1,j),即可遍历完所有情况。
使用lru cache 效率远高于使用字典存储值，函数内部返回。


### 代码
800ms左右
```python3
from functools import lru_cache
class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        @lru_cache(None)
        def find(d,i):
            if d==1:
                return max(jobDifficulty[:i+1])
            temp,t=float('inf'),0
            for j in range(i-1,d-3,-1):
                t=max(t,jobDifficulty[j+1])
                temp=min(t+find(d-1,j),temp)
            return temp
        return -1 if d>len(jobDifficulty) else find(d,len(jobDifficulty)-1)
```
1200~1800ms
```
class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        cache=dict()
        def find(d,i):
            if (d,i) in cache:
                return cache[(d,i)]
            if i>=d-1:
                if d==1:
                    cache[(d,i)]=max(jobDifficulty[:i+1])
                    return cache[(d,i)]
                t=jobDifficulty[i]
                temp=float('inf')
                for j in range(i-1,d-3,-1):
                    t=max(t,jobDifficulty[j+1])
                    temp=min(t+find(d-1,j),temp)
                cache[(d,i)]=temp
                return cache[(d,i)]
            else: return -1 
        return find(d,len(jobDifficulty)-1)
```
