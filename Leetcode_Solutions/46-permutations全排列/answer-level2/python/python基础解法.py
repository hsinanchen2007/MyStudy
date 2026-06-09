### 解题思路
主要采用的就是dfs算法，需要注意的是回溯的时候需要恢复初始状态

### 代码

```python3
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        res = []
        path = [0] * n
        st = [False] * (n)

        def dfs(u):
            if u == n:
                res.append([path[i] for i in range(n)])
                return
            
            for i in range(n):
                if not st[i]:
                    path[u] = nums[i]
                    st[i] = True
                    dfs(u+1)
                    st[i] = False
        
        dfs(0)
        return res

```