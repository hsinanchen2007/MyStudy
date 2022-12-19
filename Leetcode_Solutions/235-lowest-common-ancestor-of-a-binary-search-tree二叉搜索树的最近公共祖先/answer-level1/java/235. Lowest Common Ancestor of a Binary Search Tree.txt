```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // 如果root.val > p 且root > q, 说明 p,q均在root左子树中
        // 如果root.val < p 且root < q, 说明 p,q均在root右子树中
        // 如果root.val介于p,q之间, 说明root为lca
        // 如果root是空节点, 直接返回root;
        while(root != null){
            if(root.val > p.val && root.val > q.val) root = root.left;
            else if(root.val < p.val && root.val < q.val) root = root.right;
            else return root;
        }
        return root;      
    }
}
```

> 11.26 python

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # 当前节点 与p,q的关系
        # 交换p,q的值, 使p > q
        # 1. root.val > p root = root.left
        # 2. root.val < q root = root.right
        # 3. q <= root.val <= q return root

        while root:
            if root.val > p.val and root.val > q.val:
                root = root.left
            elif root.val < p.val and root.val < q.val:
                root = root.right
            else:
                return root
        
        return root 
```