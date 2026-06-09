### 解题思路
这一题是上一题 [168. Excel表列名称](https://leetcode-cn.com/problems/excel-sheet-column-title/)的翻转。
但是， 上一题逻辑很复杂，这一题却很简单。没有取模运算，没有 0 元素。
还需要思考。

### 代码

```python3
class Solution:
    def titleToNumber(self, s: str) -> int:
        num2str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        str2num = {num2str[i]:i+1 for i in range(len(num2str))}
        val = 0
        for x in s:
            val*=26
            val += str2num[x]
        return val
```