两次遍历，A的元素值作为B中的索引，比较占空间。
执行用时 : 68 ms, 在所有 Python3 提交中击败了93.91%的用户
内存消耗 : 13.9 MB, 在所有 Python3 提交中击败了100.00%的用户
```
class Solution:
    def largestUniqueNumber(self, A: list) -> int:
        B = [0] * (max(A)+1)
        for a in A:
            B[a] += 1
        for k in range(len(B)-1, -1, -1):
            if B[k] == 1:
                return k
        return -1
```
