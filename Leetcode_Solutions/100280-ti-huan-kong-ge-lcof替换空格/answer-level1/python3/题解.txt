### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def replaceSpace(self, s):
        """
        :type s: str
        :rtype: str
        """
        S=s.replace(' ','%20')
        return S
```

既然是替换，作为一个懒惰的人，我们搜先想想有没有内置方法，于是我们便使用replace将空格参数替换掉