### 解题思路
代码极其简单易读

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
    

    int res;

    public int sumEvenGrandparent(TreeNode root) {
        
        res = 0;
        helper(null, null, root);
        return res;
    }

    private void helper(TreeNode grandP, TreeNode father, TreeNode node) {
        if(node == null) return;

        if(grandP != null && grandP.val % 2 == 0) {
            res += node.val;
        }
        
        helper(father, node, node.left);
        helper(father, node, node.right);
    }
}
```