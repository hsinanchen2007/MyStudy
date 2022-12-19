### 解题思路

将输入数字转换成字符串
比较字符串逆序是否与该字符串相同，判断是否为回文数。

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        string = str(x)
        if string[::-1] == string:
            return True
        return False
```