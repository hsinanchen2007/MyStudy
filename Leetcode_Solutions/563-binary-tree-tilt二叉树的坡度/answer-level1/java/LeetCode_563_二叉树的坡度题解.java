### 解题思路

题目的重点在于：

**节点的坡度**定义即为，该节点左子树的结点之和和右子树结点之和的差的绝对值。空结点的的坡度是0

整个树的坡度就是**其所有节点的坡度之和。**

思路就是，每次递归中计算出当前节点的坡度，并返回当前节点的节点之和，提供给上级节点计算。

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
    
    private int tilt;

    public int findTilt(TreeNode root) {
        tilt = 0;
        dfs(root);
        return tilt;
    }

    private int dfs(TreeNode root) {
        if (root != null) {
            int leftTilt = dfs(root.left); // 左节点的值
            int rightTilt = dfs(root.right); // 左节点的值
            int selfTilt = Math.abs(leftTilt - rightTilt); // 节点自身的坡度
            tilt = tilt + selfTilt;
            return root.val + leftTilt + rightTilt;  // 自身以及子节点之和
        }
        return 0;
    }
}
```