### 解题思路


### 代码

```python
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n==1:
            return str(n)
        count=1
        B=""
        A = self.countAndSay(n-1)+"-"
        print(A)
        for i in range(1,len(A)):
            if A[i-1] == A[i]:
                count+=1
            else:
                B+=str(count)+A[i-1]
                count=1
        return B
                
```