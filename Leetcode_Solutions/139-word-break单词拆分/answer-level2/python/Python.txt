### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def wordBreak(self, s, wordDict):
        help=[0 for i in range(len(s)+1)]
        help[0]=1
        for i in range(1,len(s)+1):
            for j in range(i):
                if help[j] and s[j:i] in wordDict:
                    help[i]=1
                    break
        return help[len(s)]==1
```