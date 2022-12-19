### 解题思路
此处撰写解题思路
暴力破解，哈哈哈哈哈哈
### 代码

```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s) == 0:
            return True
        number = len(t)
        isTrue = []
        for j in range(len(s), 0, -1):
            for i in range(number, 0, -1):
                if t[i-1] == s[j-1]:
                    number = i-1
                    isTrue.append(number)
                    break
                if i-1 == 0:
                    return False
        if len(isTrue) == len(s) and len(isTrue)>0:
            return True
        else:
            return False
```