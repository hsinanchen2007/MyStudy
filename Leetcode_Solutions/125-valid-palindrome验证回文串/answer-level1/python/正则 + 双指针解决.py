### 解题思路
1. 利用正则将字符串里的数字还有字母提取出来并全部转成小写
2. 双指针左右扫描匹配即可

### 代码

```python3
import re

class Solution:
    def isPalindrome(self, s: str) -> bool:
        if str is None:
            return True

        letters = "".join(re.findall(r'[0-9A-Za-z]', s)).lower()
        left = 0
        right = len(letters) - 1

        while left <= right:
            if letters[left] != letters[right]:
                return False
            left += 1
            right -= 1
        return True
```