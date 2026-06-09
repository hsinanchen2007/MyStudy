### 解题思路
先產生一組跟s一樣長的 List
再觀察有哪些 子集出現在s 當中
出現的位置在 List中+1
最後觀察 有哪些位置大於1 那些小於 1

### 代码

```python3
class Solution:
    def addBoldTag(self, s: str, dict: List[str]) -> str:
        record = []
        for i in range(0, len(s)):
            record.append(0)

        for c in dict:
            if len(c) > len(s):
                continue
            for i in range(0, len(s) - len(c) + 1):
                if c in s[i:]:
                    for j in range(s[i:].index(c) +i, s[i:].index(c) + len(c)+i):
                        record[j] += 1

        res = ""
        flag = False
        for i in range(0, len(record)):
            if record[i] > 0 and flag == False:
                flag = True
                res += "<b>"
                res += s[i]
            elif record[i] > 0 and flag == True:
                res += s[i]   
            elif record[i] == 0 and flag == True:    
                flag = False
                res += "</b>"
                res += s[i]
            else:
                res += s[i]  
        
        if flag:
            res +=  "</b>"

        return res
```