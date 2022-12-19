### 解题思路
bin()返回转为二进制的字符串
汉明距离为两个二进制串的异或(x^y)后的"1"的个数
使用bin(x^y).count('1')即可

### 代码

```python3
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        return bin(x^y).count('1')
```