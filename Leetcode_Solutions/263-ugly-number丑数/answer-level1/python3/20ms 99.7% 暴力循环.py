### 解题思路
这题直接循环即可

需要注意的是直接返还 num == 1 的隐式bool值要快得多

### 代码

```python3
class Solution:
    def isUgly(self, num: int) -> bool:
        if num == 0:
            return False
        while num % 2 == 0:
            num /= 2
        while num % 3 == 0:
            num /= 3
        while num % 5 == 0:
            num /= 5
        return num == 1

```