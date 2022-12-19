### 解题思路
从内向外循环去括号 最后变成空字符串就是有效的 
注意由于空格也是有效的 直接在最前面去掉所有空格

### 代码

```python
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s.replace(' ','')
        while '()' in s or '[]' in s or '{}' in s:
            s = s.replace('()','')
            s = s.replace('[]','')
            s = s.replace('{}','')
        
        return  s == ''

              
```