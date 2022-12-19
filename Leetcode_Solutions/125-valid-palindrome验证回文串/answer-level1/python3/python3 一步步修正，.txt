
看到判断回文，会想用递归，但是又是大小写不敏感，又是不考虑符号和空格，于是最开始的时候的判断是`ord(i)>=ord('a')andord(i)<=ord('z')`，
但是这样就会在例如`'0P'`的测试用例上挂掉，因为直接没有考虑到数字的情况，于是改为判断`if i.isalnum()`，但是这样递归超内存了
```
class Solution:
    def isPalindrome(self, s: str) -> bool:
        ss = ''
        for i in s:
            i = i.lower()
            if i.isalnum():
                ss += i
        return self.check(ss)
        
    def check(self, s):    
        if len(s) <= 1:
            return True
        
        return s[0] == s[-1] and self.check(s[1:-1])
```

于是就准备用循环来判断，那么就用双指针，然后从首和尾往中间遍历，如果遇到非数字和字母的，就跳过，必须要i和j对应的元素都为数字或字母才开始判断：
```
class Solution:
    def isPalindrome(self, s: str) -> bool:
        i = 0
        j = len(s)-1
        
        while i < j:
            if s[i].isalnum() and s[j].isalnum():
                if s[i].lower() != s[j].lower():
                    return False
                i += 1
                j -= 1
            if not s[i].isalnum():
                i += 1
            if not s[j].isalnum():
                j -= 1
        return True
```
