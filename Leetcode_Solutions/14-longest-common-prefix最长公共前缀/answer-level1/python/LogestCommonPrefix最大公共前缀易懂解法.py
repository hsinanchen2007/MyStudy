### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs)== 0: return ''
        str = strs[0]
        for i in range(len(strs)):
            while  strs[i].find(str)!=0:
                str = str[:-1]

        return str
```