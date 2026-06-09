利用广度搜索算法来求解。

### 代码

```python
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        queue=[('',n,n)]
        result=[]
        while queue:
            res,left,right=queue.pop()
            if left==0 and right==0:
                result.append(res)
            if left>0:
                queue.append((res+'(',left-1,right))
            if right>left and right>0:
                queue.append((res+')',left,right-1))
        return result   

      
```