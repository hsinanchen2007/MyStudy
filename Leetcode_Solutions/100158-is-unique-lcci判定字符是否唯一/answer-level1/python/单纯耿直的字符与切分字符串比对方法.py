### 解题思路
第一次来leetcode写代码，思路比较单纯耿直，还请给位大佬不吝赐教。
思路非常单纯，就是借用python的in来检测字符串中是否有被查找字符char
为了避免查找到自己的尴尬局面，每个字符都会先被从字符串中切取出来再进行查询
切去的方法就是生成一个去掉了第i个char的cut_astr
以上，感谢各位
### 代码

```python
class Solution(object):
    def isUnique(self, astr):
        """
        :type astr: str
        :rtype: bool
        """
        for i,char in enumerate(astr):
            cut_astr = astr[:i]+astr[i+1:]
            if char in cut_astr:
                return False
        return True
```