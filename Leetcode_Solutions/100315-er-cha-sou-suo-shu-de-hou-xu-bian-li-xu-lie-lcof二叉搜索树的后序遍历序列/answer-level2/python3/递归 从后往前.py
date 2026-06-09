```
class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        def judge(i, j):
            if i >= j : return True 
            end = j - 1
            while end>=i and postorder[end] > postorder[j]:
                end -= 1
            for p in range(i, end+1):
                if postorder[p] > postorder[j]: return False 
            return judge(i,end) and judge(end+1, j-1)
        return judge(0, len(postorder)-1)
```
