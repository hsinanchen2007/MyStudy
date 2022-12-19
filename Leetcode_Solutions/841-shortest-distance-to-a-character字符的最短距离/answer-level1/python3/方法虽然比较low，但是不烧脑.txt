### 解题思路

刚学python，只会这个，mark一下

### 代码

```python3
class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        list1 = []
        list2 = []
        for i in range(len(S)):
            for j,v in enumerate(S):
                if v == C:
                    list1.append(abs(i - j))     
            list2.append(min(list1))
            list1 = []
        return (list2)
```