### 解题思路
思路比较简单
- 使用字典记录每个字符出现的次数
- 回文串要求左右对称，所以对统计的字符次数除以2，作为能够形成回文串的计数；
- 还需要考虑边界条件，也就是形成的回文串的长度不应该大于原字符串长度

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        lgth = len(s)
        if lgth < 2:
            return lgth
        
        dct = {}
        for item in s:
            if item not in dct.keys():
                dct[item] = 1
            else:
                dct[item] += 1
        
        cnt = 0
        for val in dct.values():
            cnt += (val // 2)
            pass
        
        return min(cnt*2+1, lgth)
```