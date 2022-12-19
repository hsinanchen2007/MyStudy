```python
class Solution:
    def longestLine(self, M: List[List[int]]) -> int:

        # Time complexity : O(M*N)
        # Space complexity : O(N)

        if M == []: return 0
        top = [0] * len(M[0])
        res = 0
        # horizontal, vertical
        for i in range(len(M)):
            left_cnt = 0
            for j in range(len(M[0])):
                if M[i][j] == 1:
                    left_cnt += 1
                    top[j] += 1
                    res = max(res, left_cnt, top[j])
                else:
                    left_cnt, top[j] = 0, 0
        # diagonal
        def traverse_diag(i, j):
            if i >= len(M) or j >= len(M[0]) or M[i][j] == 0: return 0              
            M[i][j] = -1
            return 1 + traverse_diag(i + 1, j + 1)
        # anti-diagonal
        def traverse_anti_diag(i, j):
            if i >= len(M) or j < 0  or M[i][j] == 0: return 0       
            return 1 + traverse_anti_diag(i + 1, j - 1)

        def diag_scan(flag):
            tmp_res = 0
            for i in range(len(M)):
                for j in range(len(M[0])):
                    if M[i][j] == flag:
                        if flag == 1:
                            tmp_res = max(tmp_res, traverse_diag(i, j))
                        else:
                            tmp_res = max(tmp_res, traverse_anti_diag(i, j))
            return tmp_res

        res = max(res, diag_scan(1), diag_scan(-1))        
        return res
```