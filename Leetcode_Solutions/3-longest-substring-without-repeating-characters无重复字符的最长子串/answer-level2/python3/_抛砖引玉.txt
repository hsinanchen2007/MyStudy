### 解题思路

一.暴力法
两层循环，外层循环从头到尾遍历字符串，内层循环用于判断之前的字符是否和当前字符相同，并计算长度。

二.O(n)解法
假设字符串是ascii字符串，那么可以新建一个长度为256的整型数组。数组的索引为字符的ascii值，数组的值为字符上次出现的位置，-1代表没出现过。
另外声明以下变量：
`max_len`用于保存最大长度，初始化为0
`l`用于保存当前计算的无重复字串长度，初始化为0
`last`用于保存当前计算子串的起始位置
判断步骤：
遍历字符串。
1. 如果chars[char]==-1，那表示该字符没出现过，l加1。
2. 如果chars[char] > -1，那代表之前字符出现过，分以下两种情况处理
   1). 之前出现的位置在字串起始位置（last）之后，则表明当前字串遇到重复字符，计算长度，并重置字串开始位置和字串长度
   2). 之前出现的位置在字串起始位置（last）之前，那不算当前字串重复字符，l加1即可

### 代码
```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        chars = [-1] * 256
        max_len = 0
        l = 0
        last = -1
        for i in range(0,len(s)):
            char = ord(s[i])
            char_index = chars[char]
            if char_index == -1:
                l = l + 1
            else:
                if char_index > last:
                    max_len = max(l, max_len)
                    last = char_index
                    l = i - last
                else:
                    l = l + 1
            chars[char] = i
        return max(max_len, l)
```