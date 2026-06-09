### 解题思路
如果用递归函数解题，复杂度过高，而动态规划复杂度为n的平方

### 代码

```python
class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        n = len(s)
        flag = [True]+[False]*n
        for i in range(n):
            if flag[i] == True:
                for j in range(i+1, n+1):
                    if s[i:j] in wordDict:
                        flag[j] = True
        return flag[-1]
```