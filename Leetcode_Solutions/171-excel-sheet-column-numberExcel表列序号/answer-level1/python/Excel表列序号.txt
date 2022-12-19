### 解题思路
可以理解为26进制数转换为10进制数

### 代码

```python3
class Solution:
    def titleToNumber(self, s: str) -> int:
        res = 0
        for i in s:
            value = ord(i) - ord('A') + 1  # 获取到每一位的数值
            res = res * 26 + value  # 每往右边推进一位，就意味这个数字需要进位，可以理解为26进制数
        
        return res
```