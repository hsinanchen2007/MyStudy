### 解题思路
官方题解：
1. 只要求出每行的和，按照顺序排列，取前K个即可。

自己搞不明白的地方就是，lambda的的函数

### 代码

```python3
class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        n = len(mat)
        power = [sum(item) for item in mat]
        ans = list(range(n))
        ans.sort(key=lambda i:(power[i], i))

        return ans[:k]
```