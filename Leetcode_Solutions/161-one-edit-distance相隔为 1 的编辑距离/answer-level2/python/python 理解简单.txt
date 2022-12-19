### 解题思路
一次编辑距离
【1】 长度就有限制 长度不能超过1。 
【2】 遍历，第一次遇到了不一样的字符，假设坐标i，如果插入，s[i:]== t[(i+1):];如果删除：s[(i+1):] == t[i:]; 替换 s[(i+1):] == t[(i+1):]。
【3】 全程没有遇到不一样的，那么两个串就要相差1，不然不满足编辑距离为1。 

### 代码

```python
class Solution(object):
    def isOneEditDistance(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        if abs(len(s)-len(t))>1:
            return False
        # lent>=lens
        for i in range(min(len(s), len(t))):
            if s[i]== t[i]:
                continue
            return s[i:] == t[(i+1):] or s[(i+1):] == t[i:] or s[(i+1):] == t[(i+1):]
        return len(s) != len(t)
```