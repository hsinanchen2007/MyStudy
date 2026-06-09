### 解题思路
回文串无非两种：
                            偶数们 + 偶数们
            偶数们 +（奇数-1）们 + 奇数 +（奇数-1）们 + 偶数们
先做一个字母表，循环查找字母出现次数
查找次数非偶即奇
用s的长度减去奇数出现的次数
如果全为偶数不加1
有奇数次则结果加1（1是回文串的中间）
### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        i = 0
        A2z = list(map(chr,range(ord('A'),ord('z')+1)))
        for x in A2z:
            a = s.count(x)
            if a % 2 != 0:
                i += 1
        if i != 0 :
            return len(s) - i + 1
        else:
            return len(s)


```