### 解题思路
（1）由于不区分大小写，先将字符串所有字符转为大写
（2）使用re.sub处理字符串，去掉字符串中非数字和非字母的字符
（3）处理后的字符串与其反转后的字符串对比，如果相等即为回文，注意是比较值所以用==比较，不能用is

### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        import re
        resS = list(re.sub(r'\W', "", s.upper()))
        if resS == list(reversed(resS)):
            return True
        else:
            return False
```