### 解题思路
萌新上路0.0

### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:    
        if s == len(s)*' ':
            return 0
        else:
            index,length,result = -1,-len(s),''
            while True:
                if s[index] != ' ':
                    while index >= length and s[index] != ' ':
                        result = result+ s[index]
                        index -= 1
                    break
                else:
                    index -= 1
        return len(result)
```