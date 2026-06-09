### 解题思路
先化成str 然后利用string[::-1]反转  要是又负号 得考虑一下负号
最后有一个坑 就是 if -2147483648 < res < 2147483648 else 0  溢出设为0
### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        res=0
        if x>=0:
            res = int( str(x)[::-1])
        else:
            x=-x
            res = int( str(x)[::-1])*-1
        return res if -2147483648 < res < 2147483648 else 0

```