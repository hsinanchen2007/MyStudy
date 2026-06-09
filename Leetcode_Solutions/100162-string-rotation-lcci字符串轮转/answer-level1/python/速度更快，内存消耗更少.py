### 解题思路
按题目要求只查一次字符

### 代码

```python3
class Solution:
    def isFlipedString(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        if set(s1) != set(s2):
            return False
        if len(s1) < 3 :
            return True
        a = s2 + s2
        if a.count(s1):
            return True
        else:
            return False
        # if s1 == "":
        #     return True
        # flag = 0
        # for i in range(len(s2)):
        #     a = s2[i+1:] + s2[:i+1]
        #     if a == s1:
        #         flag = 1
        #         break
        # if flag == 1:
        #     return True
        # else:
        #     return False
```