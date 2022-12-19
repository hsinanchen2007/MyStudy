### 解题思路
索引奇偶筛选即可

### 代码

```python3
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        L = []
        c = 0
        for i, n in enumerate(nums):
            if i % 2 == 0:
                c = n
            else:
                L += c * [n]
                c = 0
        return L

```
执行用时 :40 ms, 在所有 Python3 提交中击败了91.13%的用户
内存消耗 :13.4 MB, 在所有 Python3 提交中击败了100.00%的用户