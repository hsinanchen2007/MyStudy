### 解题思路
斐波那契数列
通过找规律来得到一个递推公式：f(i)=f(i-1)+f(i-2) 此处i>=3
当n<=2时，f(i)=i  据此得到下面代码

### 代码

```python
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n<=2: return n
        f1,f2,f3=1,2,0
        for i in range(3,n+1):
            f3=f1+f2
            f1=f2
            f2=f3
        return f3

       
        

```