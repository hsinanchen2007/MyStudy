### 解题思路
相对比较清楚

### 代码

```python
class Solution(object):
    def pondSizes(self, land):
        """
        :type land: List[List[int]]
        :rtype: List[int]
        """
        width=len(land[0])
        height=len(land)
        history=[[0 for _ in range(width)] for _ in range(height)]
        total_result=[]
        def dfs(i,j):
            if i<0 or i >=height or j<0 or j >=width:
                return 0
            if history[i][j]:
                return 0
            else:
                history[i][j]=1
                if land[i][j]==0:
                    result=1
                    for ii in range(-1,2):
                        for jj in range(-1,2):
                            result+=dfs(i+ii,j+jj)
                    return result
                else:
                    return 0
        for i in range(height):
            for j in range(width):
                res=dfs(i,j)
                if res!=0:
                    # print dfs
                    total_result.append(res )

        return sorted(total_result)
```