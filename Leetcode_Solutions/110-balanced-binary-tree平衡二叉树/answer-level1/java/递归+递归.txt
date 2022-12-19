### 解题思路
思路非常简单，第一层递归针对当前树的根节点，求其左右子树的高度，然后看是否满足平衡二叉树要求
第二层递归求子树高度，
第一次自己写出效率这么高的递归，感谢上帝，阿门。
![image.png](https://pic.leetcode-cn.com/a7efdf4f809f13e22917c1a45f9ced5938a3f34dbc49db5e3aedaa046b245e8f-image.png)


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
    public boolean isBalanced(TreeNode root) {
        if (root == null) {
            return true;
        }
        int heightLeft = dfs(root.left, 0);
        int heightRight = dfs(root.right, 0);
        if (Math.abs(heightLeft - heightRight) > 1) {
            return false;
        }
        if (!isBalanced(root.left)){
            return false;
        } 
        return isBalanced(root.right);
    }

    public int dfs(TreeNode node, int height){
        if (node == null){
            return height;
        }
        int heightLeft = dfs(node.left, height+1);
        int heightRight = dfs(node.right, height+1);
        if(heightLeft > heightRight) {
            return heightLeft;
        }
        return heightRight;
    }
}
```