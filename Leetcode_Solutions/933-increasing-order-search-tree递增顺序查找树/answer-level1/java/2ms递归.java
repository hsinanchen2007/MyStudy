### 解题思路
递归主要分为7个部分：
1.判断当前节点为空，则返回
2.更新右子节点
3.判断左节点是否为空，空则直接返回当前节点，因为已经排好序了

如果左节点不为空，则需要下列操作：
4.整理左节点，把最左边节点的指针更新
5.左节点左子节点置空
6.通过指针找到整理好的左节点形成的树的最右节点
7.把当前节点接到第六步找到的节点之下，并把当前节点左节点置空

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
    private TreeNode newRoot;//用来存储最左边的节点
    public TreeNode increasingBST(TreeNode root) {
        newRoot=root;
        root=helper(root);
        return root;
    }
    private TreeNode helper(TreeNode node){
        if (node==null)
            return null;

        node.right=helper(node.right);

        if (node.left==null)
            return node;

        TreeNode left=helper(node.left);
        newRoot=left;

        left.left=null;

        while (left.right!=null)
            left=left.right;
        
        left.right=node;
        node.left=null;
        return newRoot;
    }
}
```