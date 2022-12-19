### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def add(self, a: int, b: int) -> int:
        a=a&0xffffffff
        b=b&0xffffffff
        while b!=0:
            carry=((a&b)<<1)&0xffffffff
            a=a^b
            b=carry
        if a<0x80000000:
            return a
        else:
            return ~(a^0xffffffff)#如果a为负数,负数在二进制中存储是以补码形式存储,先进行转换为原码-1,再进行~操作，~x 类似于 -x-1即可将负数输出。
```