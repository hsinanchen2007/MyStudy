### 解题思路
利用求余将输入的整数进行翻转，余数与初始化的翻转数相加，余数相加同时解决了示例三中个位数为0的问题。
利用python的‘<<’运算符，对数值范围进行判断，1<<31表示二进制向左移31位。
在求余相加步骤中判断翻转数范围是否溢出，溢出则返回0。
最后根据x是否大于0，返回翻转数。

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        y,reverse_x = abs(x),0
        boundery = (1<<31)-1 if x>0 else (1<<31)
        while y != 0:
            reverse_x = reverse_x*10 + y%10
            if reverse_x>boundery:
                return 0
            y = y//10
        return reverse_x if x>0 else -reverse_x
```