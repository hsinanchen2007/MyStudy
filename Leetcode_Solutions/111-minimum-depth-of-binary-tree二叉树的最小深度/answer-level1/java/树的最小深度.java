### 解题思路
这个也是在树的遍历基础上的题。
叶子节点才可以计算深度。

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
    public int depth = Integer.MAX_VALUE;
    public void getmin(TreeNode root, int depth){
        if(root == null){
            return;
        }
        if(root.left == null && root.right == null){
            this.depth = Math.min(this.depth, depth);
        }
        getmin(root.left, depth+1);
        getmin(root.right, depth+1);
    }

    public int minDepth(TreeNode root) {
        if(root == null)
            return 0;
        getmin(root, 1);
        return this.depth;
    }
}
```