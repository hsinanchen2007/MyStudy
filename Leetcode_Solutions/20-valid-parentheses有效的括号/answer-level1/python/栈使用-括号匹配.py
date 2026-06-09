### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        if not s:
            return True
        if len(s)== 1:
            return False
        temp = []
        aDict = {')':'(', ']':'[', '}':'{'}
        
        for i in s:
            if i not in aDict:
                temp.append(i)
                print("Appending %s" % i)
            elif len(temp) == 0:
                return False
            elif temp.pop() != aDict[i]:
                print("")
                return False
            
        return True if not len(temp) else False

```