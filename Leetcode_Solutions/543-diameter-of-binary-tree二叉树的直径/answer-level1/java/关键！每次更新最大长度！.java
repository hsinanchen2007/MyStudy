### 解题思路

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

    int res = 0;

    public int diameterOfBinaryTree(TreeNode root) {
        getD(root);
        return res;
    }

    private int getD(TreeNode root){
        if(root==null){
            return 0;
        }
        int leftD = getD(root.left);
        int rightD = getD(root.right);
        // 关键！每次更新最大长度！
        res = Math.max(leftD + rightD, res);
        return 1 + Math.max(leftD, rightD);
    }

}
```