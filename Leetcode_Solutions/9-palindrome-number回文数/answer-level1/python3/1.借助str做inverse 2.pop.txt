### 方法1
小于0，肯定不是回文数。
大于0，判断是否是回文 s[::-1] == s

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        if str(x)[::-1] == str(x):
            return True
        else:
            return False
```

### 方法2
小于0，肯定不是回文数。
大于0，因为是正序，所以直接做弹出操作 `rev = rev*10 + pop` 结果就是翻转后的结果

```python
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 :
            return False
        rev = 0
        x_copy = x
        while(x_copy!=0):
            pop = x_copy % 10
            x_copy = x_copy//10
            rev = rev*10 + pop
        if rev == x:
            return True
        else:
            return False
```