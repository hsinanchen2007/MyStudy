dpCost记录每个点的最小金币花费，dpInd用一个元组记录路径。
之所以不用列表而用元组的原因是Python中的元组可以直接比较大小，比较方式就是题目所说的字典序大小。
最坏的时间复杂度可以达到O(n^3)，因为每个点记录的路径长度是O(n)的，比较两条路径的字典序大小需要O(n)时间，三重循环一共需要O(n^3)的时间复杂度。最坏空间复杂度是O(n^2)。
最坏情况：A = [0] * n, B = n
```
class Solution:
    def cheapestJump(self, A: List[int], B: int) -> List[int]:
        n = len(A)
        # if B == 1:
        #     return [i + 1 for i in range(n)] if -1 not in A else []
        dpInd = [(1,)] * n
        dpCost = [sys.maxsize] * n
        dpCost[0] = A[0]
        for i in range(1, n):
            if A[i] == -1:
                continue
            curMin = (9999,)
            for j in range(max(i - B, 0), i):
                if dpCost[j] + A[i] < dpCost[i]:
                    dpCost[i] = dpCost[j] + A[i]
                    curMin = dpInd[j]
                elif dpCost[j] + A[i] == dpCost[i]:
                    if A[j] == 0:
                        curMin = dpInd[j]
                    else:
                        curMin = min(curMin, dpInd[j])
            dpInd[i] = tuple(list(curMin) + [i + 1]) 
            
        if dpCost[-1] > sys.maxsize // 2:
            return []
        return dpInd[-1]
        
```
