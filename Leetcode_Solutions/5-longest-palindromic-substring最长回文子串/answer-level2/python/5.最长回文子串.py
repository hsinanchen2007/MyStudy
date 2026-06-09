### 解题思路
- 中心扩展法；
- 从任意位置出发，找出左边所有相同的字符；找出右边相同的字符；（这样可以不讨论奇数长度、偶数长度的情况）
- 左右同时扩展时，中间部分都是相同的字符，可能时1个或者多个；一直扩展到两边不对称时结束，得到回文子串；
- 为了找到最长回文子串，需要遍历列表，重复上述操作；仅当新发现的子串更长时才更新已有的子串；

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s)<=1:return s
        res = ''
        for i in range(0,len(s)-1):
            left = i-1
            right = i+1
            while left>=0 and s[left]==s[i]:
                left = left - 1
            while right<len(s) and s[right]==s[i]:
                right = right + 1

            while left>=0 and right<len(s) and s[left]==s[right]:
                right = right + 1
                left = left - 1
            
            if len(res)< (right-1-(left+1)+1):
                res = s[left+1:right] 
        return res
            
```