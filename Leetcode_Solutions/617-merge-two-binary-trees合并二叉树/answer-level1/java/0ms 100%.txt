### 解题思路
如果当前节点t1,t2都为空，则返回null,
如果当前节点t1为空，则返回t2,
如果当前节点t2都为空，则返回t1,
如果当前节点t1,t2都不为空，则把t1值改为t1,t2的和，继续递归左右节点。

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
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        return helper(t1,t2);
    }
    private TreeNode helper(TreeNode t1, TreeNode t2){
        if (t1==null && t2==null)
            return null;
        else if (t1==null)
            return t2;
        else if (t2==null)
            return t1;
        else{
            t1.val=t1.val+t2.val;
            t1.left=helper(t1.left,t2.left);
            t1.right=helper(t1.right,t2.right);
            return t1;
        }
    }
}
```