### 解题思路


### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False
        res=0
        tmp=x
        while x:
            res=res*10+x%10
            x//=10
        return res==tmp
```