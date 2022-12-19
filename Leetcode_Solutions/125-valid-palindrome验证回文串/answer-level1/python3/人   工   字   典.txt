### 解题思路
我会手撸特殊符号了23333
 (不知道isallnum(), 哭了
### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.upper()
        L = {" ":" " ,
            ",":",", 
            ";":";",
            ":":":", 
            ".":".", 
            "?":"?",
            "/":"/",
            "<":"<",
            ">":">",
            "{":"{", 
            "}":"}",
            "[":"[", 
            "]":"]",
            "\\":"\\",
            "|":"|",
            "!":"!",
            "#":"#",
            "$":"$",
            "%":"%", 
            "^":"^",
            "&":"&",
            "*":"*",
            "@":"@", 
            "-":"-",
            "\"":"\"",
            "\'":"\'",
            "(":"(",
            ")":")", 
            "`":"`", 
            "~":"~"
        }
        for i in L:
            if L[i] in s:
                s = s.replace(i, "")
        left, right = 0, len(s) - 1
        while left < right:
            if s[left] != s[right]:
                return False
            left += 1
            right -= 1
        return True
```

我吐了