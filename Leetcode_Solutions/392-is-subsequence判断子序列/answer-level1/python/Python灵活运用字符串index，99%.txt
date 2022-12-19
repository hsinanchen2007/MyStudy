### 解题思路
对子串s中的逐个字符进行查找，若查找失败，直接返回False，否则更新下次查找起始下标。

![image.png](https://pic.leetcode-cn.com/6fa17774f1980818b26dbcea215f7c3fcb4fe3ad9681c501d197b5f1aac8d67d-image.png)


### 代码

```python
class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        beg = 0
        for char in s:
            if char in t[beg:]:
                beg = t.index(char, beg)+1
            else:     
                return False
        return True
```