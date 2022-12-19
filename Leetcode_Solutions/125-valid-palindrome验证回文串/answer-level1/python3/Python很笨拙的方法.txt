### 解题思路
一直不想用特别成型的函数，因为之前写过反转字符串这里就偷懒用了[::-1]，方法其实都挺笨的，很直接的思路。
转小写，去符号，反转然后比较。

### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        snew = ''
        s = s.lower()
        for i in s:
            if i in 'abcdefghijklmnopqrstuvwxyz0123456789':
                snew = snew + i
        snew = snew.lower()
        srnew = snew[::-1]
        if snew == srnew:
            return True
        else:
            return False
```