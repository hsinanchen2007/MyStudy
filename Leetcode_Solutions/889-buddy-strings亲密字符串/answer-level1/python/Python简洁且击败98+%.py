只要分以下几种情况讨论即可：
1. 长度不相等, 直接False
2. A==B, A中有重复字符True, 否则Fasle
3. 不相同位置不等于2, Fasle; 等于2且可交换True, 否则False
```
class Solution(object):
    def buddyStrings(self, A, B):
        n_A, n_B = len(A), len(B)
        if n_A <> n_B: return False
        if A == B:
            for c in A:
                if A.count(c) > 1: return True
        diff = []
        for i in range(n_A):
            if A[i] <> B[i]: diff.append((A[i], B[i]))
        if len(diff) <> 2 or (diff[0][0] <> diff[1][1] or diff[0][1] <> diff[1][0]): return False
        return True
```
