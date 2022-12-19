### 解题思路
本质上是字符串遍历和进制转换
1、A-1 B-2 …… Z-26
2、倒着遍历，指数相加就行（字母比较容易转化数字，所以直接用asc了）

### 代码

```python3
class Solution:
    def titleToNumber(self, s: str) -> int:
        return sum(26**i*(ord(j)-64) for i,j in enumerate(s[::-1])) 
```