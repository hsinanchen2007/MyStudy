### 解题思路
![IMG_20200325_110448.jpg](https://pic.leetcode-cn.com/39f44675c53bd7c973dea0a52dbed24e6fc974b002ae7eebe8eb3ea95a234c70-IMG_20200325_110448.jpg)


### 代码

```python3
class Solution:
    def isNumber(self, s: str) -> bool:
        s = s.strip()
        state = 0
        for i in range(len(s)):
            c = s[i]
            if state == 0:
                if '0'<= c <= '9':
                    state = 1
                elif c in ["+", "-"]:
                    state = 2
                elif c == '.':
                    state = 7
                else:
                    return False
            elif state == 1:
                if '0'<= c <= '9':
                    state = 1
                elif c == ".":
                    state = 3
                elif c in ["E", "e"]:
                    state = 4
                else:
                    return False
            elif state == 2:
                if '0'<= c <= '9':
                    state = 1
                elif c == '.':
                    state = 7
                else:
                    return False
            elif state == 3:
                if '0'<= c <= '9':
                    state = 6
                elif c in ["E", "e"]:
                    state = 4
                else:
                    return False
            elif state == 4:
                if '0'<= c <= '9':
                    state = 5
                elif c in ["+", "-"]:
                    state = 7
                else:
                    return False
            elif state == 5:
                if '0'<= c <= '9':
                    state = 5
                else:
                    return False
            elif state == 6:
                if '0'<= c <= '9':
                    state = 6
                elif c in ["E", "e"]:
                    state = 4
                else:
                    return False
            elif state == 7:
                if "0" <= c <= "9":
                    state = 6
                else:
                    return False

        return state in [1, 3, 5, 6]
```