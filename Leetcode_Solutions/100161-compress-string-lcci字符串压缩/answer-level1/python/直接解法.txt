### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def compressString(self, S):
        """
        :type S: str
        :rtype: str
        """
        l_o = len(S)

        num = 0
        str_n = []
        old_str = ' '
        for st in S:
            if st is not old_str:
                str_n.append(str(num))
                str_n.append(st)
                num = 1
                old_str = st
            else:
                num += 1

        str_n.append(str(num))
        str_n.pop(0)
        if len(str_n) >= l_o:
            return S
        else:
            return ''.join(str_n)
```