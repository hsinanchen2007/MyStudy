### 解题思路
双指针

### 代码

```python3
class Solution:
    def diStringMatch(self, S: str) -> List[int]:
        i = 0
        j = len(S)
        result = []
        for k in range(len(S)):
            if S[k] == 'I':
                result.append(i)
                i += 1
            else:
                result.append(j)
                j -= 1
        # result.append(i)
        return result + [i]
```