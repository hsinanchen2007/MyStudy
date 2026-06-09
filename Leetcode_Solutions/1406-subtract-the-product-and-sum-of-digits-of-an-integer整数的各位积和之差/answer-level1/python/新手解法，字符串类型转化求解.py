### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def subtractProductAndSum(self, n):
        """
        :type n: int
        :rtype: int
        """
        nmultiply=1
        nsum=0
        for i in str(n):
            m=int(i)
            nmultiply*=m
            nsum+=m
        result=nmultiply-nsum
        return result
n=234
solution=Solution()
print(solution.subtractProductAndSum(n))

```