### 解题思路
大体逻辑是求解树左边和右边最大深度

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

    public int calDepth(TreeNode node){
        if(node == null)
            return 0;
        return 1 + Math.max(calDepth(node.left), calDepth(node.right));
    }

    public int maxDepth(TreeNode root) {
        return calDepth(root);
    }
}
```