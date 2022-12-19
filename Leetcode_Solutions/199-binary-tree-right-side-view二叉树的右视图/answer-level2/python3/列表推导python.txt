```python
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if(root is None):return []
        ans,d=[],[root]
        while(d):
            ans.append(d[-1].val)
            d=[c for p in d for c in (p.left,p.right) if c]
        return ans;
```
