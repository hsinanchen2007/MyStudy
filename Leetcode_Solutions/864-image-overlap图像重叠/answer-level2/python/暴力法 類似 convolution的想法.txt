### 解题思路
類似 convolution的想法將兩隻影像再不同情況下重疊 
並且計算重疊部分街唯一的像素數量

### 代码

```python3
class Solution:
    def largestOverlap(self, A: List[List[int]], B: List[List[int]]) -> int:
        if len(A) == 1:
            return A[0][0] * B[0][0]

        vec = []
        for i in range(0, len(A)):
            vec.append(i) 
        vec = [-1]*(len(A)-1) + vec + [-1]*(len(A)-1)        

        max_summ = 0
        step = len(vec) - len(A)
        for i in range(0, step):
            for j in range(0, step):
                summ = 0
                for idxi, m in enumerate(vec[i:i+len(A)]):
                    for idxj, n in enumerate(vec[j:j+len(A)]):                        
                        if m == -1 or n == -1:
                            continue
                        summ += min(A[m][n], B[idxi][idxj])      
                max_summ = max(max_summ, summ)
        return max_summ        

```