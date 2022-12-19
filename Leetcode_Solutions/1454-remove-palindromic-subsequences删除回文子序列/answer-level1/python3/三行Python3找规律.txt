### 解题思路
题目意思是每次删除一个子序列，这个子序列必须是回文。由于子序列的元素可以不连续，且字符串只有`a`和`b`组成，而 n 个 a 本身是一个回文子序列，所以第一次先删除所有的`a`，再删除所有的`b`就行了。
### 代码

```python
class Solution:
    def removePalindromeSub(self, s: str) -> int:
        if s == '': return 0
        elif s == s[::-1]: return 1  # 如果字符串是回文，直接全部删除即可。
        else: return 2  # 如果字符串不是回文，我们最多需要删两次。
        
```
### 复杂度分析
- 时间复杂度：$O(N)$。
- 空间复杂度：$O(1)$。