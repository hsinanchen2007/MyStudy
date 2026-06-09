### 解题思路
暴力法查找使得满足的数，时间复杂度O(n*m),其中，n和m是A，B的长度。

### 代码

```python3
class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        g_a = int((sum(A) + sum(B)) / 2 - sum(A))
        res = []
        for item in A:
            if item + g_a in B:
                res.append(item)
                res.append(item+g_a)
                break
        return res

```