### 解题思路
加了一个优化小技巧：如果剩下的字符串长度小于当前最长回文串长度的一半，就直接结束，速度提升了一半，看来测试数据里很长的回文串还是不少哈哈

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        re = (0,0)
        for i in range(len(s)):
            left = i-1
            right = i+1
            while left>=0 and s[left]==s[i]:
                left -= 1
            while right<len(s) and s[right]==s[i]:
                right += 1
            while left>=0 and right<len(s) and s[left]==s[right]:
                left -= 1
                right += 1
            if right-left>re[1]-re[0]:
                re = (left,right)
            # 优化小技巧：如果剩下的字符串长度小于当前最长回文串长度的一半，就直接结束
            if (len(s)-1-i)*2 < re[1]-re[0]: break
        return s[re[0]+1:re[1]]

```