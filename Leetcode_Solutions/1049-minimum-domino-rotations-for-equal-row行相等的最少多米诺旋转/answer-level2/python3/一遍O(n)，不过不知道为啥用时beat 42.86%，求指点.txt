### 解题思路
一遍O(n)遍历和O(1)遍历，挑候选项和统计两部分各自数值的数量
一遍O(1)遍历计算返回结果

### 代码

```python3
class Solution:
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        cnt, A_cnt, B_cnt = [0] * 7, [0] * 7, [0] * 7
        for i in range(len(A)):
            A_cnt[A[i]] += 1
            B_cnt[B[i]] += 1
            if A[i] == B[i]:
                cnt[A[i]] += 1
            else:
                cnt[A[i]] += 1
                cnt[B[i]] += 1
        candidate = []
        for cand, c in enumerate(cnt):
            if c >= len(A):
                candidate.append(cand)

        if len(candidate) == 0:
            return -1
        res, n = 2147483647, len(A)
        for cand in candidate:
            res = min(res, min(n-A_cnt[cand], n-B_cnt[cand]))
        return res
        

```