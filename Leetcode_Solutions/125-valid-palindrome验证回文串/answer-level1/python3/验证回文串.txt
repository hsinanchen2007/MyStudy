### 解题思路
一，利用正则表达式将字符串中的非数字和字母去除掉，然后将只含数字和字母的字符串进行切片反转，相等即为回文串。
新学[str.join(iterable)](https://docs.python.org/3.6/library/stdtypes.html?highlight=join#str.join)方法，将iterable中的string连接到str中去，若iterable中出现非string，报[TypeError](https://docs.python.org/3.6/library/exceptions.html#TypeError)
![image.png](https://pic.leetcode-cn.com/b74726735ed68c78bcde55cb6ed439b5e1d8ac75c83a48684a3f62da51402255-image.png)

### 代码

```python3
import re
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        s = re.split(r'[`!~@#$%\^&*()\-+_={}\[\]:\";\'\\<>\?,\./\s]*\s*',s)
        str_s = ""
        str_s = str_s.join(s)
        if str_s == str_s[::-1]:
            return True
        else:
            return False

```

二、利用双指针，一前一后依次向中间前进比较，遇到非数字和字母则跳过。
新学[str.isalnum()](https://docs.python.org/3.6/library/stdtypes.html?highlight=isalnum#str.isalnum)方法，哈哈哈，检查是否为字母和数字
![image.png](https://pic.leetcode-cn.com/3db87acfd1e47ddb433298b962d7aef6b7c62486d9560ba3f73871f0665f7580-image.png)

```
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        right = len(s) - 1
        left = 0
        while left < right:
            if not s[left].isalnum():
                left += 1
                continue
            if not s[right].isalnum():
                right -= 1
                continue
            if s[left] != s[right]:
                return False
            else:
                left += 1
                right -= 1
        return True
```