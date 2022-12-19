### 解题思路
此处撰写解题思路
1）现将数字转化为二进制数，用bin，但是注意，python转后的数字前缀有0b,估，我先把数字转化为字符串，然后去掉前面的前缀
2）从后往前处理二进制位，按照8,4,2,1的基本原则，如果当前位置为0，则产生增益，做累加，否则不累加，最终输出累加的数值即可
### 代码

```python3
class Solution:
    def findComplement(self, num: int) -> int:
        b = str(bin(num))
        b = b[2:]
        out = 0
        by = 1
        for c in b[::-1]:
            if c == "0":
                out += by
            by *= 2 # 1,2,4,8准则

        return out
```