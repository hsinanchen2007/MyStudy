### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        '''
        if x<0 or (x%10==0 and x!=0):
            return False
        res = 0
        while x>res:
            res = res*10+x%10
            x = x//10
        return x==res or x==res//10
        '''
        
        return str(x) == str(x)[::-1]
        '''
        lst = list(str(x))
        while len(lst)>1:
            if lst.pop(0)!=lst.pop():
                return False
        return True
        '''
        '''
        lst = list(str(x))
        L,R = 0,len(lst)-1
        
        while L<=R:
            if lst[L]!=lst[R]:
                return False
            L+=1
            R-=1
        return True
        '''
```