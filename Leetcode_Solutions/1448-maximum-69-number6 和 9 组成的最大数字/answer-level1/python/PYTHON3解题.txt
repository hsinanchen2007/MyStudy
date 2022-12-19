### 解题思路
当找到第一个为6的字符时，得到需要的结果

### 代码

```python3
class Solution:
    def maximum69Number (self, num: int) -> int:
        num =str(num)
        length =len(num)
        for ch in num:
            length =length-1
            if ch =="6":
                num =int(num)+3*(10**length)
                return num
                break
        return num


```