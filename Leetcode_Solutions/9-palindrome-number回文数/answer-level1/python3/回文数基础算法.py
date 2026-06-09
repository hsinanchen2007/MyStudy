简单分类后再进行比较
小于零的值由于有负号所以不是
个位数字是
最后再进行对大正整数的判断（转化为字符串）
```
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False
        elif x>=0 and x<10:
            return True
        else:
            a=str(x)
            if a==a[::-1]:
                return True
            else:
                return False
```
