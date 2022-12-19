数据大到O(2n)时间都这么慢了吗，提交记录里一堆100-200ms的是不是当时都没这么大数据啊。。

```
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        if N==1:
            return 1
        d=collections.defaultdict(int)      #统计入度数
        for i,j in trust:
            d[i]-=1     #存在出度就减成无效数据
            d[j]+=1
        for i in d:
            if d[i]==N-1:
                return i
        return -1
```
