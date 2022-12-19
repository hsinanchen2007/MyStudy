### 解题思路
本来自己是选择的注释中的那种初始化方式，但是没有考虑到浅拷贝的问题，就是修改了sub[1]中的项的话，sub[2]中的项也会随着改变，这样的话就会出现问题
所以应该使用[[0]*2000 for i in range(2000)]的这种初始化方法，这样外层列表的每一项都指向一个不同的对象，修改其中一个，不会影响其他的值

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s or len(s) == 1:
            return s
        maxStart, maxEnd = 0, 0
        maxLen = 1
        sub = [[0]*len(s) for i in range(len(s))]
        #这种初始化的方法可以，以后的二维数组可以这样初始化
        #sub = [[0]*2000]*2000
        #需要记住的是，上面的这种写法，自己最后会被拷贝的问题搞到，其中一个值修改为1以后，好多会受到影响
        #初始化记录长度的数组
        for e in range(1, len(s)):
            for l in range(0, e+1):
                if s[l] == s[e] and (e - l <= 2 or sub[l+1][e-1] == 1):                    
                    sub[l][e] = 1
                    if e - l + 1 > maxLen:
                        maxStart, maxEnd = l, e
                        maxLen = e - l + 1
        if maxEnd == len(s) - 1:
            return s[maxStart:]
        return s[maxStart:maxEnd + 1]
        #动态规划的方法，用空间来换时间
```