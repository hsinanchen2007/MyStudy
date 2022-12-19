### 解题思路
求最小全部覆盖的面积

### 代码

```python3
class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        '''傻子才这么做呢
        def countop(ans, opera):
            for i in range(opera[0]):
                for j in range(opera[1]):
                    ans[i][j] += 1
            return ans
        
        if not ops:
            return m*n
        elif len(ops) == 1:
            return ops[0][0]*ops[0][1]
        #ans = [[0]*n]*m 不可用，每行是浅拷贝
        ans = [[0] * n for i in range(m)]
        for x in ops:
            ans = countop(ans, x)
        return sum(tmp.count(ans[0][0]) for tmp in ans)
        '''
        
        if not ops:
            return m*n
        tmp = list(zip(*ops))   #复习zip(*list)用来做二维列表转置
        return min(tmp[0])*min(tmp[1])
```