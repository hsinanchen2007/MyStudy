### 解题思路
1、首先处理特殊情况：个位数返回True，负数返回False
2、遍历str，遇到不对称的即返回False，否则遍历完成也没有返回False时返回True

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        num = str(x)
        if len(num) == 1:
            return True
        if num[0] == '-':
            return False
        for i in range(len(num)):
            if num[i] != num[len(num) - 1 - i]:
                return False
        return True
```