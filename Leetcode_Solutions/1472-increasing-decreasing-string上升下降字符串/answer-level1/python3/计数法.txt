### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def sortString(self, s: str) -> str:
        counter = [0] * 26
        for char in s:
            counter[ord(char) - 97] += 1
        res = ""
        while len(res) < len(s):
            for i in range(26):
                if counter[i] > 0:
                    res += chr(i + 97)
                    counter[i] -= 1
            for i in range(25, -1, -1):
                if counter[i] > 0:
                    res += chr(i + 97)
                    counter[i] -= 1
        return res
```
![image.png](https://pic.leetcode-cn.com/af5a560056cb16811c4e99e5c261db3e0fbedffc313d7054dbde05a3caedbf6a-image.png)
