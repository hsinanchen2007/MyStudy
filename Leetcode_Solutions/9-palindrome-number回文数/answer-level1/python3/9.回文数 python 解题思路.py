### 解题思路
借鉴最长回文子字符串的想法，回文字符串的头尾两个字符一样。首先将负数的判定为False， 而且0-9的整数为回文数，剩下的情况根据以下思路判断：
1、将数字转化为string
2、设头尾两个index，若这两个位置字符一致，则不断往中间移动
3、若r-l=1（字符串长度为偶数），则为回文数；或者更改index后l=r也为回文数（说明这个字符串长度为奇数）
4、都不是以上情况，则不是回文数


运行时间比反转一半数字的方法在Python中更快一些

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        str_x = str(x)
        if len(str_x) == 1:
            return True
        l = 0
        r = len(str_x) - 1
        while l<len(str_x) and r >=0 and str_x[l] == str_x[r]:
            if r - l == 1:
                return True
            l += 1
            r -= 1
            if l == r:
                return True
        return False
        
```