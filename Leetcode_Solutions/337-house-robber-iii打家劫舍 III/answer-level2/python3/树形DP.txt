(这是一个很经典的树形dp问题)

我们可以先不管这个否是二叉树,我们发现,如果我们选了 cur 这个节点 那么就说明 我们不能选它的所有子节点(还有父节点)。
对于每一个节点，都只有选和不选两种情况。我们每次考虑一棵子树，那么根只有两种情况，选和不选(我们让dp[0]表示不选,dp[1]表示选)。
    对于选择了根,那么我们就不能选它的儿子了
    如果没有选根，我们就可以任意选了(即选最大的那一个)
然后我们做一次dfs即可

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    def dp(self , cur : TreeNode) -> List[int] :
        
        
        if not cur :
            return [0,0]
        
        l = self.dp(cur.left)
        r = self.dp(cur.right)
        
        
        return [max(l)+max(r),cur.val+l[0]+r[0]]
    def rob(self, root: TreeNode) -> int:
        return max(self.dp(root))
        
        
```

