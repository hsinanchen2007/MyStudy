![QQ图片20200222225409.jpg](https://pic.leetcode-cn.com/8143becd256c9f86380217623bd2473cb57096b59fc978cf60e323ebe95352eb-QQ%E5%9B%BE%E7%89%8720200222225409.jpg)
```
class Solution:
    def isPalindrome(self, x: int) -> bool:
        res = 0
        y = x
        if x==0 or x%10==x:
            return True
        else:
            if x!=abs(x) or x%10==0:
                return False
            else:
                while y!=0:
                    res = res*10 + y%10
                    y//=10
                if res==x:
                    return True
                else:
                    return False
```
