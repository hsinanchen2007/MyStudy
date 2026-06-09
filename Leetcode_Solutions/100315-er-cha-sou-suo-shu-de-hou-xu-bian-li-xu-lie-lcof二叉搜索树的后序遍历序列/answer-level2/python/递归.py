### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        if not postorder:return True
        def partion(l,r):
            if l>=r:return True
            ind = l 
            while ind<r and postorder[ind]<=postorder[r]:
                ind+=1
            for i in range(ind,r):
                if postorder[i]<=postorder[r]:return False
            return partion(l,ind-1) and partion(ind,r-1)
        return partion(0,len(postorder)-1)

```