### 解题思路
for循环从长度1到len(str1),
对每个子串token先检查长度: 是否都能被str1和str2整除,
再检查是否token * k 刚好就是str1, 此处k = len(str1) // len(token)
最后把最大的那个子串取出来返回即可

### 代码

```python3

class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str2 not in str1 and str1 not in str2:
            return ""
        L = []
        for i in range(1, len(str1)):
            token = str1[:i + 1]
            if (len(str1) % len(token) != 0) or (len(str2) % len(token) != 0):
                continue
            if  token * (len(str1) // len(token)) == str1 and token * (len(str2) // len(token)) == str2:
                L.append(token)
        max_token = ''
        # print("L", L)
        for string in L:
            if len(string) > len(max_token):
                max_token = string
        return max_token
            
```