### 解题思路
方法比较简单,执行耗时有点多

### 代码

```python
class Solution(object):
    def isLongPressedName(self, name, typed):
        """
        :type name: str
        :type typed: str
        :rtype: bool
        """
        i=0
        pre=name[0]
        l=1
        for i in range(1,len(name)):
            print pre,l
            if name[i]==pre:
                l+=1
                continue
            #现在来到了一个不同的字符面前
            if typed.startswith(pre*l):
                typed=typed.lstrip(pre)
            else:
                return False
            pre=name[i]
            l=1
        if typed.startswith(pre*l):
            return True
        else:
            return False
```