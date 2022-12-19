### 解题思路
1. 将 num 转 字符串，再转list
2. 遍历list，遇到第一个 '6', 即改为'9'，退出循环
3. 将list 转 字符串，再转 int

### 代码

```python
class Solution(object):
    def maximum69Number (self, num):
        """
        :type num: int
        :rtype: int
        """
        strs = list(str(num))
        for s in strs:
            if s == '6':
                strs[strs.index(s)] = '9'
                break            
        
        return int(''.join(a for a in strs))
```