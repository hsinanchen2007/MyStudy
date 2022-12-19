### 解题思路
之前笔试碰到过也没有做出来过。
现在拿到也想不到具体的简单方法。
看了下评论区的讲解，**通过将二叉树的直接转换为：二叉树的每个节点左右两子树的高度和的最大值**
因而结合该方法求解路径

定义全部私有变量`maxDiameter = 0;`
而后通过`depthBinaryTree(root)`方法求解每个节点的高度。
若`root == null`，则高度为0.
若`root.left == null && root.right == null`，则高度为1，其余情况按照如下进行求解
先通过`left = depthBinaryTree(root.left);`求得左子树的高度，
再通过`right =  depthBinaryTree(root.right);`求得右子树的高度，
将这两个高度相加，即为该结点的最大直径长度，在和maxDiammeter进行大小比较，得到最大值：`Math.max(maxDiameter, left + right);`
而后返回`Math.max(left, right) + 1;`
注意必要加上1，因为当前节点也算一个高度。

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
    private int maxDiameter = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        depthBinaryTree(root);
        return maxDiameter;
    }

    public int depthBinaryTree(TreeNode root){
        if(root == null) return 0;
        else if(root.left == null && root.right == null) return 1;
        int left =  depthBinaryTree(root.left);
        int right =  depthBinaryTree(root.right);
        maxDiameter = Math.max(maxDiameter, left + right);
        return Math.max(left, right) + 1;
    }
}
```