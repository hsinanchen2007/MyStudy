### 解题思 单次操作：主要是判断两节点以及左右节点是否对称，
终止条件：左右全为空，其中一个为空，全部不为空（判断其值是否相等）

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
    public boolean isSymmetric(TreeNode root) {
        if(root==null) return true;
        return isEqual(root.left,root.right);
    }
    public boolean isEqual(TreeNode left,TreeNode right){
        if(left==null&&right==null) return true;
        if(left==null||right==null||left.val!=right.val) return false;
        return isEqual(left.left,right.right)&&isEqual(left.right,right.left);
    }
}
```