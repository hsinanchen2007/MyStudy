### 解题思路
对于负数，直接返回False
对于小于10的正数，返回True
对于10的倍数，返回False
剩余的数，通过取余法计算转换后的数，并比较是否与原数字相同


### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        if x < 10:
            return True
        if x % 10 == 0:
            return False
        reverse = 0
        rest = x
        digit = 0
        while rest:
            digit = rest % 10
            reverse = reverse * 10 + digit
            rest //= 10
        if reverse == x:
            return True
        return False

```