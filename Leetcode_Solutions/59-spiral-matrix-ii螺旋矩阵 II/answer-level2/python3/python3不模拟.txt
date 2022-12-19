类似于之前那道题
```
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        if not n:
            return []
        def helper(matrix):
            ans = []
            m = len(matrix)
            n = len(matrix[0])
            for i in range(len(matrix) // 2):
                matrix[i], matrix[len(matrix) - i - 1] = matrix[len(matrix) - i - 1], matrix[i]
            for i in range(0, n):
                ans.append([matrix[j][i] for j in range(m)])
            return ans
        ans = [[n**2]]
        t = n*n-1
        while t:
            ans = helper(ans)
            ans.insert(0,[x for x in range(t-len(ans[0])+1,t+1)])
            t -= len(ans[0])
        return ans
```
