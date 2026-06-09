### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s :
            return " "
        str_dict = {}
        for i in s:
            str_dict[i]= 1 if not str_dict.get(i) else str_dict[i]+1
        
        for i in s :
            if str_dict[i]==1:
                return i
        return  " "
```