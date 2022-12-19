### 解题思路
代码比较冗长，大佬们见笑了；
创建一个dict来找对应的字母
创建一个digit列表来储存计算出来每一位的字母，但是此处是从个位数开始存的
iteration:
当数字大于或等于16时 找%16余数 如果valid就添加到digit列表里 然后新的数字变成整数部分接着来
最后将digit列表使用切片reverse过来 

### 代码

```python3
class Solution:
    def toHexspeak(self, num: str) -> str:
        rst = ""
        mapping = {10:"A", 11:"B", 12:"C", 13:"D", 14:"E", 15:"F", 1:"I", 0:"O"}
        digit = []
        dev = int(num)
        i = 0
        while dev >= 16:
            res = dev % 16
            if res not in mapping.keys(): return "ERROR"
            digit.append(mapping[res])
            dev = (dev-res)/16
        if dev not in mapping.keys(): return "ERROR"
        digit.append(mapping[dev])
        for i in range(len(digit)):
            rst = rst + digit[i]
        return rst[::-1]
```