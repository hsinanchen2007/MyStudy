
该方法仅用4行代码即可实现，但是效率较低。

**匹配模式：**
正则表达式中，'\1'字符串可以表示上一个group的复制。r'(.)\1'即可表示两个重复的字符，r'(.)\1\1'可表示三个，以此类推。因此，本题中待匹配字符串可以用r'(.)' + r'\1'*(k-1)表示。

**判断条件：**
re.search(pattern, str)方法可以在字符串str中搜索pattern，并返回第一个成功匹配的pattern（位置和字符串），如无匹配则返回None。

**删除方法：**
re.sub(pattern, '', str)方法可以删除字符串中所有符合条件的pattern。

```python []
class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        pattern = r'(.)' + r'\1'*(k-1)
        while re.search(pattern, s):
            s = re.sub(pattern, '', s)
        return s
```

（头部没有写import re仍然可以顺利运行，偷鸡成功XD）