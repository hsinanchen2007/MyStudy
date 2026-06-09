### 解题思路

### 代码

```python3
class Solution:
    def exchangeBits(self, num: int) -> int:
        numb = '{:b}'.format(num)   #将十进制转换为二进制
        if len(numb) % 2: numb = '0'+numb
        ans = ''; i = 1
        while i <= len(numb):
            ans += numb[-(i+1)]
            ans += numb[-i]
            i += 2
        ans = ans[::-1]   #将字符串倒置
        return int(ans, 2)

```