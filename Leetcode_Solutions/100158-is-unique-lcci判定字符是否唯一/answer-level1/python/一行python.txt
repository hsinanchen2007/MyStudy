### 解题思路
set一下比较长度就行
执行用时 :16 ms, 在所有 Python 提交中击败了100.00%的用户
内存消耗 :11.7 MB, 在所有 Python 提交中击败了100.00%的用户
### 代码

```python
class Solution(object):
    def isUnique(self, astr):
        """
        :type astr: str
        :rtype: bool
        """
        return len(set(astr))==len(astr)
```