### 解题思路
比较简单

### 代码

```python
class Solution(object):
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        temp=list(S)
        result=[999999 for _ in range(len(temp))]
        def change_temp(i,result):

            result=[min(abs(ii-i),x) for ii,x in enumerate(result)]
            return result

        for i,cc in enumerate(S):
            if cc==C:
                result=change_temp(i,result)
        return result
```