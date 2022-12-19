### 解题思路
很直接的思路，借用额外空间。

### 代码

```python3
class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        A1 = []
        for i in A:
            t = i[::-1]
            A1.append(t)
        for i in range(len(A1)):
            for j in range(len(A1[0])):
                if A1[i][j] == 1:
                    A1[i][j] = 0
                else:
                    A1[i][j] = 1
        return A1
```