### 思路
寻找每行字符串中的字符在原字符串中的索引的规律：
| 行 |   第1个字符 |   第2个字符 |   第3个字符 |   第4字符  |  第5个字符 |   ...... |
| --- | --- | --- | --- | --- | --- | --- |
| 0 |   0  |         +2n-2 |      +2n-2 |       +2n-2 |    +2n-1 | ...... |
| 1 |   1  |         +2n-2-2  |   +2  |         +2n-2-2 |  +2 |         ...... |
| . |
| i   | i  |          +2n-2-2i  |  +2i |         +2n-2-2i | +2i |        ...... |
| . |
| n-1 | n-1 |        +2n-2 |      +2n-2  |      +2n-2 |    +2n-1 |      ...... |

注：+ 表示在本行前一字符在原字符串中的索引的基础上加

### 代码
```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        n = numRows
        if len(s)<=1 or n<=1:
            return s
        i = 0
        r = ''
        for i in range(n):
            isNextSingle = True
            j = i
            while 1:
                try:
                    r += s[j]
                    if i!=0 and i!=n-1:
                        if isNextSingle:
                            j += 2*n - 2 - 2*i
                            isNextSingle = False
                        else:
                            j += 2*i
                            isNextSingle = True
                    else:
                        j += 2*n - 2
                except IndexError:
                    break
        return r
```
### 时间复杂度
外部for循环n次，内部的while最多循环$2|s|/n$次，总的时间复杂度大约为$\Omega(2|s|)$。