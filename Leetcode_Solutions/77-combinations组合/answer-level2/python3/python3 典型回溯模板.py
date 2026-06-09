### 解题思路
此处撰写解题思路
典型的回溯算法，索引去重，不选择已经选择过的元素。

### 代码

```python3
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = []

        def helper(n,index,k,t):
            if k==0:
                ans.append(t[:])

            for i in range(index,n+1):
                t.append(i)
                helper(n,i+1,k-1,t)
                t.pop()

        t=[]
        helper(n,1,k,t)        
        return ans
                

```