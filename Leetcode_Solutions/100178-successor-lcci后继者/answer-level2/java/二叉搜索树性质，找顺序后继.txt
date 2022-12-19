### 解题思路
1.p存在右子树，那么p的后继就是p.right子树的最左节点
2.p不存在右子树，那么p的后继就是p所在子树的最近左孩子的父节点

### 代码

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
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        // p存在右子树，直接后继就是右子树的最左节点
        if (p.right != null){
            p = p.right;
            while (p.left != null){
                p = p.left;
            }
            return p;
        }
        // p不存在右子树
        TreeNode node = root;
        TreeNode res = null;
        while (p != node){
            if (p.val < node.val){
                // node比p大，表示node在p的后继路径上
                res = node;// 左孩子的父节点
                node = node.left;
            }else {
                // node比p小，表示node在p的前驱路径上
                node = node.right;
            }
        }
        return res;
    }
}
```