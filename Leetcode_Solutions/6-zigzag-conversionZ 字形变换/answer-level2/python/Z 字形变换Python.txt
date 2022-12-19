先看看本方法的执行效果：

__执行用时 : 76 ms, 在ZigZag Conversion的Python3提交中击败了99.21% 的用户<br/>__
__内存消耗 : 13.1 MB, 在ZigZag Conversion的Python3提交中击败了87.93% 的用户__

观察首行很容易得到步长`step=numRows+numRows-2`。<br/>
当`numRows=4`时，`step=6`，有如下变幻：
```
row
0    6k+0                   => i % step = row
1    6k+1  6k+5=6k+(6-1)    => i % step = row  i % step = step - row
2    6k+2  6k+4=6k+(6-2)    => i % step = row  i % step = step - row
3    6k+3                   => i % step = row
```
有此可以推导出：
```i % step = row```和```i % step = step - row```<br/>
因此```row = i % step```和```row = step - i % step```(余数大于```numRows```)

可以有如下伪代码：
``` python
c = ['', '', '', ''] # len(c) = numRows
for i in range(len(s)):
    mod = i % step
    if mod < numRows :
        c[mod] += s[i]
    else :
        c[step - mod] += s[i]
```
最后再将`c`转换成字符串即可。

完整的代码如下
```python
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows <= 0:
            raise RuntimeError("illegal numRows.")
        if numRows == 1 or numRows >= len(s):
            return s
        
        step = numRows + numRows - 2
        c = ['' for i in range(numRows)]

        for i in range(len(s)) :
            mod = i % step
            if mod < numRows :
                c[mod] += s[i]
            else :
                c[step - mod] += s[i]

        res = ''
        for i in c:
            res += i
        return res
```
