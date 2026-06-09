### 解题思路
简单的采用了判断语句。考虑几个边界条件即可。时间12ms。

### 代码

```python
class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans = 0
        for i in range(len(s)-1, -1, -1): # "aa "
            if s[i] != ' ':
                ans = ans + 1
            if ans > 0 and s[i] == ' ':
                return ans
        if len(s)>0:  ## 防止'aaaa'
            return ans
        return 0 # 防止空''
```