直接遍历把第一个 6 改成 9 就行。

用 python 很方便，但是需要注意 python 的字符串是不可变的，需要转成 list 方便操作（当然我是从 int 转成 str 再转成了 list）

```python
class Solution:
    def maximum69Number (self, num: int) -> int:
        x = list(str(num))
        for i in range(len(x)):
            if x[i] == '6':
                x[i] = '9'
                break
        return int(''.join(x))
```

在题目评论里看到别人（https://leetcode-cn.com/u/thebestone/）的解法，太强了

```python
class Solution:
    def maximum69Number (self, num: int) -> int:
        return int(str(num).replace('6','9',1))
```