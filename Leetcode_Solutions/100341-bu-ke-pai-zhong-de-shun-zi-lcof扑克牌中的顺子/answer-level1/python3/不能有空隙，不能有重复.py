### 解题思路
此处撰写解题思路

### 代码

```python

# -*- coding:utf-8 -*-
class Solution:
    def isStraight(self, numbers):
        if len(numbers) < 5 or len(numbers) > 5:
            return False
        numbers = sorted(numbers)
        n0 = 0
        for i in range(4):
            if numbers[i] == 0:
                n0 += 1
        start = n0
        if numbers[-1] - numbers[start] > 4:
            return False
        else:
            if len(set(numbers[start:])) != len((numbers[start:])):
                return False
            else:
                return True

```

```python
```