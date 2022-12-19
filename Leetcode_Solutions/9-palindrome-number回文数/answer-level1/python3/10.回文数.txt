### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x > 0 and x % 10 == 0) : return False
        rev = 0
        if x == 0: True
        while rev < x:
            rev *= 10
            # 一次云环 就乘以10，因为提取此时x 的最后一位
            rev += x%10
            # 提取最后一位
            x = x//10
            # 去掉最后一位
        if rev >x:
            rev = rev//10
        if rev == x: 
            return True
        else: 
            return False
# 1234 5 4321
# 10000 00001
```