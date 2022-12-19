### 解题思路
1.使用正则表达式，先将字符串中非字母或数字的字符用sub去掉再统一成小写，并进行反转；
2.判断两个字符串是否相等，返回。

### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        ss = re.sub(r'\W','',s).lower()
        ss_reverse = ss[::-1]

        if ss == ss_reverse:
            return True
        else:
            return False
```