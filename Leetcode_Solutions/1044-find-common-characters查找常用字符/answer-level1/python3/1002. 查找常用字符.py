### 解题思路

### 代码

```python3
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        ans = list(A[0])
        for i in A:
            temp = list(i)
            copy = ans.copy()
            for j in copy:
                if j not in temp: ans.remove(j)
                else: temp.remove(j)
        return ans





```