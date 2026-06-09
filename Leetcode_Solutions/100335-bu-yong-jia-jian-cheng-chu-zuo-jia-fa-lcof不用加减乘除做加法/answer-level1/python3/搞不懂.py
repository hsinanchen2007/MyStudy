### 解题思路
此处撰写解题思路

### 代码

```python

# -*- coding:utf-8 -*-
class Solution:
    def add(self, num1, num2):
        if not num1:
            return num2
        if not num2:
            return num1
        while num2:
            temp = (num1 ^ num2)&0xFFFFFFFF
            num2 = ((num2 & num1) << 1)&0xFFFFFFFF
            num1 = temp
        return num1 if num1<=0x7FFFFFFF else ~(num1)^0xFFFFFFFF #<=,xian ~ 

```

