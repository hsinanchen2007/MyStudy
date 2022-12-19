解题思路：自底向上累加有效节点数，与q和p相同的节点值为1，不同的为0，当第一个累加有效节点数为2的节点即为最近公共祖先。

如果能在第一个count=2的时候直接终止递归，可能会更快。

```
class Solution {
    TreeNode res = null;
    int count = 0;
    boolean first = true;
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        lowest(root, p, q);
        return res;
    }

    private int lowest(TreeNode root, TreeNode p, TreeNode q){
        if(root==null) return 0;
        int temp = 0;
        if(p.val == root.val || q.val==root.val)
            temp = 1 ; 
        count = lowest(root.left, p, q)+lowest(root.right, p, q)+temp;
        if(first && count == 2){
            res=root;
            first=!first;
        }
        return count;
    }
}
```
