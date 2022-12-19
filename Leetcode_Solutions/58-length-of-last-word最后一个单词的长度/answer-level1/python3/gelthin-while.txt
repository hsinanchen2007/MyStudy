### 解题思路
善用 while 循环

没必要总是用 for 循环把所有东西都套进去。
刚开始想写一个大的for循环，当找到最右边第一个不为 " " 的位置，在内部再写一个 while 循环

从右往左搜索，首先用 while 循环找到最右边第一个不为 “ ” 的数。
然后再用 while 从此位置遍历, 直到结束或者碰到一个 “ ”，记录下长度。

### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        n = len(s)

        leng = 0
        i = n-1
        while i>=0:
            if s[i] == " ":
                i -= 1
            else:
                break
        if i < 0:
            return 0
        while i>=0:
            if s[i] != " ":
                leng += 1
                i -= 1
            else:
                break
        return leng

```