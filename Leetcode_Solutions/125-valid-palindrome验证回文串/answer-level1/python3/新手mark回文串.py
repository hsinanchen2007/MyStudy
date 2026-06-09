### 解题思路
1.利用re匹配去掉符号
2.把字符串换成大写进行比较
### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        import re
        temp = re.sub('[\W_]+','',s)

        if temp[::1].upper() == temp[::-1].upper():
            return True
        else:
            return False
```