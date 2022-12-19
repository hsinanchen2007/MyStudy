### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        A={}
        result=0
        for i in tasks:
            if i not in A:
                A[i]=1
            else:
                A[i]+=1
        a=len(A)
        B=sorted(A.values())
        b=B[-1]
        c=len(tasks)
        result=(n+1)*(b-1)+1
        for i in range(len(B)-2,-1,-1):
            if B[i]==B[-1]:
                result+=1
        if c>result:
            return c
        else:
            return result
```