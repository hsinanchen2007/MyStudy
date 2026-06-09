### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        temp = ""
        result = ""
        count = 0
        for i in range(len(S)):
            if temp != S[i]:
                if count != 0:
                    result = result + temp + str(count)
                    count = 0 
                temp = S[i]
                count = 1
            else:
                count = count + 1   
        if count != 0:
            result = result + temp + str(count)
        if len(result) >= len(S):
            return S
        else:
            return result

```