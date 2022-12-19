```
class Solution:
    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        i, j = 0, 0
        res = []
        while i < len(A) and j < len(B):
            a = A[i]
            b = B[j]

            # 获取两个区间的 交集段
            overlap = [max(a[0], b[0]), min(a[1], b[1])]
            # 判断是否是合法交集段，是的话加入结果集合
            if overlap[0] <= overlap[1]:
                res.append(overlap)
            # overlap 的右端点来自 a/b, 来自哪一个说明那个区间的历史任务完毕，对应指针后移
            if overlap[1] == a[1]:
                i += 1
            elif overlap[1] == b[1]:
                j += 1
                    
        return res
```
