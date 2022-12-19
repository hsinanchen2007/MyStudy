### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def fib(self, n: int) -> int:
        # 递归法 超出时间限制
        '''
        if n<=1:
            return n
        else:
            return self.fib(n-1)+self.fib(n-2)'''
        def helper(dic,n):
            if n not in dic:
                dic[n]=helper(dic,n-1)+helper(dic,n-2)
            return dic[n]%1000000007
        if n<=1:
            return n
        dic={}
        dic[0]=0
        dic[1]=1
        return helper(dic,n)
 
            
        
        
   


```