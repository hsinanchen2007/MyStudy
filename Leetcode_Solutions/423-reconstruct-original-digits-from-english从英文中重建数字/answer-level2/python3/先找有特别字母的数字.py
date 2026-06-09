## 思路:

看字符串的长度，知道回溯超时，

但是我们发现

`zero`中`z`是唯一的

`two`中`w`是唯一的

`four`中`u`是唯一的

`six`中`x`是唯一的

那么，通过唯一字母知道 相应的 数字的个数

那么 `one`的个数就是 `o`总个数- `zero`个数-`two`个数-`four`个数，

同理可得其他！

## 代码:

```python
class Solution:
    def originalDigits(self, s: str) -> str:
        s = collections.Counter(s) 
        zero = s["z"]
        two = s["w"]
        four = s["u"]
        six = s["x"]
        eight = s["g"]
        one = s["o"] - zero - two - four
        three = s["t"] - eight - two
        five = s["f"] - four
        seven = s["s"] - six
        nine = s["i"] - six - eight - five
        res = ""
        for idx, val in enumerate([zero, one, two, three, four, five, six, seven, eight, nine]):
            res += str(idx) * val
        return res
```

