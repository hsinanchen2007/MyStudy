### 解题思路
其实是个简单题，最后两行是最理想的情况：字符串包含除了空格之外的字符，并且空格不在开头或结尾。

当然库函数replace也可以用，但是这题本来就很简单了，再调用库函数，就失去练习的意义了吧。不过是不是有人要说以下的代码里考察了字符串的啥呢？

### 代码

```python3
class Solution:
    def replaceSpace(self, s: str) -> str:
        res = []
        for i in range(len(s)):
            if s[i] == ' ':
                res.append('%20')
            else:
                res.append(s[i])
        return ''.join(res)

        # words = s.split()
        # return '%20'.join(words)

```