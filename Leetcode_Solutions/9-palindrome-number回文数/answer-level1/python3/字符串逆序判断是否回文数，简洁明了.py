### 解题思路
先判断是否负数，是负数直接返回False
将Int转换为str，通过字符串的逆序操作判断两者是否是回文数

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        else:
            str = x.__str__()
            new_str = str[::-1]

            if new_str == str :
                return True
            else:
                return False
```