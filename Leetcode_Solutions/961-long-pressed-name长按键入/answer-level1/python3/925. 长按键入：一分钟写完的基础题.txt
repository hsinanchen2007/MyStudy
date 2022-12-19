用好find()函数，适用于各种子字符串匹配。

![image.png](https://pic.leetcode-cn.com/311a1d06bbf62adaca3aa1a45cdee8fee7c8cb82100d3bf5ec52a5f4c5590599-image.png)

```py
class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        i = 0
        for c in name:
            j = typed.find(c, i)    #第二个参数是检索起点
            if j == -1:
                return False
            i = j + 1               #更新检索起点
        return True
```

上面的代码可以AC但还是不够严谨，下面的代码可以判定是否是重复按字母而不是瞎按的，就算存在子序列，但瞎按的也应该返回False。

```py
class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        if name and typed.find(name[0]) != 0:
            return False
        i = 0
        for c in name:
            j = typed.find(c, i)
            if j == -1 or (i > 0 and typed[i - 1: j] != typed[i - 1] * (j - i + 1)):    #判断重复字符是否成立
                return False
            i = j + 1
        return typed[i - 1: ] == typed[i - 1] * (len(typed) - i + 1) if i < len(typed) else True
```

比如下面这几个用例，用第一段代码运行返回的是True，子序列是成立的没错，但并不符合题意，只有第二代码才能返回正确答案，不过官方用例里似乎并没有这样严格的数据，但是直接在控制台里测试这样的数据的时候，返回结果和第二段代码是一样的。

```
"abc"
"axcydz"
```
```
"abc"
"aabbcx"
```
```
"abc"
"xaabbcc"
```

