### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        # 想到最好的方式就是直接split,但是直接用库函数良心过不去
        # 自己编写一个split算法吧。。。
        # 去掉最后面的空格，很简单，就不写了，直接用库吧
        s = s.rstrip()
        def splitFun(str, char):
            res = []
            slow = 0
            fast = 0
            str += char
            for i in str:
                if i == char:
                    res.append(str[slow:fast])
                    slow = fast+1
                fast += 1
            return res
        res = len(splitFun(s, " ")[-1])
        return res
```