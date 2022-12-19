### 解题思路
暴力

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

    int nodeCount = 0;

    public int countNodes(TreeNode root) {
        if(root == null) 
            return nodeCount;

        countNodes(root.left);
        countNodes(root.right);

        nodeCount++;

        return nodeCount;
    }
}
```