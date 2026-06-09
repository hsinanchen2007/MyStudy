### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def romanToInt(self, s):
        dic = {
            "I":1, 
            "V":5, 
            "X":10, 
            "L":50, 
            "C":100, 
            "D":500,
            "M":1000
         }

        result = 0
        for i in range(len(s)):
            if i < len(s)-1:
                if dic[s[i]]>=dic[s[i+1]]:
                    ant = 1
                else:
                    ant = -1
                result += ant*dic[s[i]]
            if i == len(s)-1:
                result += dic[s[i]]
        return result
```