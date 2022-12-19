### 解题思路
思路比较简单：
- 依次遍历罗马数字中的每一个字符；
- 按照字典的方式，将每一个字符对应的数字添加到统计结果中；
- 如果当前字符大于前一个字符，说明当前字符与前一个字符组成特殊字符，所以要将前一个字符的数值剪掉，并且再加上当前字符与前一个字符所代表的数字之差，作为统计结果；
- 更新前一个字符的取值；
- 按照上述方式，依次遍历，最后输出即可；

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        dct = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        prev = 1001
        rst = 0
        for item in s:
            val = dct[item]
            if val > prev:
                rst -= prev
                val = val - prev
            rst += val
            prev = val + 0
            pass
        return rst
```