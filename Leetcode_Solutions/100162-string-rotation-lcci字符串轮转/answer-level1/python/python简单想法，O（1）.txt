### 解题思路
思路很简单
1.如果两个字符串长度不相等，那一定不是轮转字符，返回False
2.长度相等，如果是轮转字符，将其中一个字符两次相加，其中一定包含另一个字符。


当然也可用sorted()排序后比较，时间复杂度较高。

### 代码

```python
class Solution(object):
    def isFlipedString(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if len(s1) != len(s2):
            return False
        else:
            ss = s2 + s2
            if s1 in ss:
                return True
            
        
```