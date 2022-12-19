### 解题思路
创建列表和字典，列表用于遍历运算，字典用于添加字符

### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        set_, temp, ret = {1:'I', 4:'IV', 5:'V', 9:'IX', 10:'X', 40:'XL', 50:'L', 90:'XC', 100:'C', 400:'CD', 500:'D', 900:'CM', 1000:'M'}, [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1], ''
        while num != 0:
            for i in temp:
                if num - i >= 0:
                    num, ret = num - i, ret + set_[i]
                    break
        return ret
        
```