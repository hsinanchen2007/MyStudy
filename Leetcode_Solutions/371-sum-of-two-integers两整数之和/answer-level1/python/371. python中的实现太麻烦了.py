### 解题思路
二进制的异或运算相当于不进位加法。
二进制的与运算相当于捕获进位点。
因此两整数相加，等同于两整数异或运算的值，加上与运算左移一位的值，迭代执行，直到进位点为零。

### 注意
python中整数不是 32 位的。

### 代码

```python3
class Solution:
    def getSum(self, a: int, b: int) -> int:
        mask = 0x100000000
        max_int = 0x7fffffff
        min_int = 0x80000000
        while b:
            a, b = (a^b) % mask, ((a&b)<<1) % mask
        
        return a if a <= max_int else ~((a%min_int)^max_int)


```