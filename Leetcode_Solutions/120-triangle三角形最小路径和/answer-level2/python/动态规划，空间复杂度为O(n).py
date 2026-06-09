### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        dp 保存上一层经过第i个元素的最小路径和
        转移：
        停在本层的第j个元素的最小路径和=min(上一层的第j-1,第j个元素)+本层的第j个元素
        注意到本层的第0个和最后一个是边界要单独处理
        """
        if not triangle:
            return 0
        N = len(triangle)
        sumPath = triangle[0]
        for i in range(1, N):
            newSumPath = [sumPath[0]+triangle[i][0]]
            for j in range(1,i):
                newSumPath.append(min(sumPath[j-1], sumPath[j])+triangle[i][j])
            newSumPath.append(sumPath[-1]+triangle[i][-1])
            sumPath = newSumPath
        return min(sumPath)
```