### 解题思路
本题采用preorder的方式，记录访问到的x，y的信息：包括他们的深度和他们的parent。
最后再比较一下。

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
    private TreeNode px;
    private TreeNode py;
    private int dx;
    private int dy;
    public boolean isCousins(TreeNode root, int x, int y) {
        preorder(root, x, y, null, 0);
        return px!=py && dx==dy;
    }
    private void preorder(TreeNode root, int x, int y, TreeNode p, int d){
        if(root==null){
            return;
        }
        if(root.val==x){
            px = p;
            dx = d;
        }
        if(root.val==y){
            py = p;
            dy = d;
        }
        preorder(root.left, x, y, root, d+1);
        preorder(root.right, x, y, root, d+1);
    }
}
```