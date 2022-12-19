### 解题思路
因为要求只能在前面增加字母，因此可以在s中找到位置i，使得[0,i]为回文。因为是最长回文，因此可以从最后位置逆序寻找，一旦找到就停止。
另外，直接调用python的s=s[::-1]是最后不超时的关键 -_-b

### 代码

```python3
class Solution:
    def shortestPalindrome(self, s: str) -> str:
# 可以在s中找到一个位置i，使得[0-i]之间形成回文，且该回文长度最长
        if len(s) <= 1:
            return s
        for i in range(len(s)-1,0-1,-1): # 逆序查找
            if s[i] == s[0]: # 稍微减少时间
                if self.validPalindrome(s[:i+1]):
                    lastIndex = i
                    break
        if lastIndex == len(s):
            return s
        else:
            return  s[:lastIndex:-1] + s
            
    def validPalindrome(self, s):
        return s==s[::-1]
```