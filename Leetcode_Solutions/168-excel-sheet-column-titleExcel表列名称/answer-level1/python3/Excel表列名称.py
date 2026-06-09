### 解题思路
本题相当于将十进制数转换成26进制数；
不过这里需要注意的是与普通26进制不同的是：这里是1-26，没有0位；

### 代码

```python3
class Solution:
    """
    本题本质上即将整数n转换成26进制；
    """
    def convertToTitle(self, n: int) -> str:
        if n < 1:
            return ''
        
        res = ''
        while n:
            tmp = n%26
            if tmp == 0:
                res = 'Z'+res
                n -= 1
            else:
                res = chr(ord('A')+tmp-1) + res
            n //=26
        return res
```