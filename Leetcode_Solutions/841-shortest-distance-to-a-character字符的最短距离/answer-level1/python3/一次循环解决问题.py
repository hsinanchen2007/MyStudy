### 解题思路
先找到字母，再倒叙赋值
### 代码

```python3
class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        index =list(range(len(S)))
        start_index = -1
        count = 0
        for i, s in enumerate(S):
            if s != C:
                index[i] = count
            else:
                index[i] = 0
                count = 0
                if start_index == -1:
                    start_index = i
                    for j, k in enumerate(range(i - 1, - 1, -1), start=1):
                        index[k] = j
                else:
                    middle = (i - start_index - 1) // 2
                    for j, k in enumerate(range(i - 1, i - middle - 1, -1), start=1):
                        index[k] = j
                    start_index = i
            count += 1
        return index
```