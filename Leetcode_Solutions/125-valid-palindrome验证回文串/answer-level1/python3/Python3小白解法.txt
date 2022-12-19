### 解题思路
当s=""时，用split（）将s变为空列表，如果s不为空，将s全部变为小写或大写，并且建立空字符串a，将s中字母和数字全部加入a中，最后将a与a的取反a[::-1]进行对比，如果a==a[::-1]则返回TRUE 否则返回False。
### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        if len(s.split())==0:
            return True
        else:
            s=s.lower()
            a=""
            for i in s:
                if "a"<=i<="z" or "0"<=i<="9":
                    a+=i
            if a==a[::-1]:
                return True
            else:
                return False
```