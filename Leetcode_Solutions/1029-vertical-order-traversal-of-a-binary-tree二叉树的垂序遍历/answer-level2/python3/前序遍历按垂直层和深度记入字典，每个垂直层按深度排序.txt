![image.png](https://pic.leetcode-cn.com/e9fb9b1271973a7b9f56bbe92a252b01037476b5d75da2740f9a6e9336a3f177-image.png)


```
class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        d={}
        imin,imax=float('inf'),-float('inf')
        def f(r,i=0,h=0):
            if r:
                if i not in d:
                    d[i]=[[h,r.val]]
                else:
                    d[i]+=[[h,r.val]]
                nonlocal imin,imax
                imin=min(imin,i)
                imax=max(imax,i)
                f(r.left,i-1,h+1)
                f(r.right,i+1,h+1)
        f(root)
        ans=[]
        for i in range(imin,imax+1):
            d[i].sort()
            ans+=[[j[1] for j in d[i]]]
        return ans
```
