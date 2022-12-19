### 解题思路
求解深度很经典的算法。和前序中序后序遍历一样需要很熟练的写出来。

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
    
    public int calculate(TreeNode node){
        if(node == null)
            return 0;
        else
            return 1 + Math.max(calculate(node.right), calculate(node.left));
    }

    public int maxDepth(TreeNode root) {
        return calculate(root);
    }
}
```