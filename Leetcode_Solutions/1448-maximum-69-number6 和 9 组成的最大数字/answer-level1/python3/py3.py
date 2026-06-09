### 解题思路
方法一：不用replace()函数
方法二：用replace()函数

### 代码
```python3
class Solution:
    def maximum69Number (self, num: int) -> int:
        num = list(str(num))
        for i in range(len(num)):
            if  num[i] == '6':
                num[i] = '9'
                break
        return int(''.join(num))
```
```python3
class Solution:
    def maximum69Number (self, num: int) -> int:
        return int(str(num).replace('6','9',1))
```