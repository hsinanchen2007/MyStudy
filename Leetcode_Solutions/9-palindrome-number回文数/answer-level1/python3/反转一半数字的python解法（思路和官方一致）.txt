思路：将数字折半反转，对比两部分是否一致，需要讨论负数、尾数是0的特殊情况
解法：
```python []
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x % 10 == 0 and x != 0):
            return False
        revnum = 0
        while(x>revnum):
            revnum = revnum*10 + x % 10
            x = x//10
        return x == revnum or x == revnum//10
```


