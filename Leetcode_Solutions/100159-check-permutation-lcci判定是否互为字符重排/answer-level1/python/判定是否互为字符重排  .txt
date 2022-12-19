### 解题思路
1.分别计算s1和s2中每个字母的出现次数；
2.然后比较

### 代码

```python3
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        count1 = [0 for _ in range(26)]
        count2 = [0 for _ in range(26)]

        for s in s1:
            count1[ord(s) - 97] += 1
        for s in s2:
            count2[ord(s) - 97] += 1
        
        for i in range(26):
            if count1[i] != count2[i]:
                return False
        return True
```