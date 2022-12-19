### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) <= 1:return len(s)
        #指定字符串的初始值和最长字符串的初始长度
        tmp = s[0]
        res = 0
        for i in s[1:]:
            #循环判定每个新的字符是否在当前字符串中，有的话则去掉第一个
            while i in tmp:
                tmp = tmp[1:]
            #加入当前字符
            tmp += i
            #比较当前字符串长度和历史最长字符串长度选出最大的
            res = max(res,len(tmp))
        return res

```