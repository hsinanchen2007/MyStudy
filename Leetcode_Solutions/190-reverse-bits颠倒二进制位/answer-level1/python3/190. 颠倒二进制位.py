### 解题思路
输入为一个无符号十进制整数，将输入转为二进制，去除前缀0b，左侧填充0，补齐32位，翻转字符串，转为十进制输出
用到的python函数：
bin(): 十进制转二进制
x.zfill(num):x右对齐，左边补0，填充到num位
x[::-1] :反转操作
int(x,base): base 存在时，视 x 为 base 类型数字，并将其转换为 10 进制数字。


### 代码

```python3
class Solution:
    def reverseBits(self, n: int) -> int:
        y = bin(n)[2:]
        y = y.zfill(32)
        y = y[::-1]
        reverse = int(y,base=2)
        return reverse
```