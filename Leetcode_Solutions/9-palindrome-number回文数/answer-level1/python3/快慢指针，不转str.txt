### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        r = 0
        if x<0:return False
        if x<10:return True
        x2 = x
        while x2>99:
            x,t=divmod(x,10)
            r=r*10+t
            x2=x2//100
        return r*10+x%10==x//10 if x2>9 else r==x//10

```