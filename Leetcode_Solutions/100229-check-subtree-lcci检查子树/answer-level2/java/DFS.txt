### 解题思路
树A是树B的子树
当且仅当，在树B中存在某节点X，其中X的节点值与A的根节点值相同，并且X的左子树与A的左子树 && X的右子树与A的右子树相同
递归的思想

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
    public boolean checkSubTree(TreeNode t1, TreeNode t2) {
        if (t2 == null)
            return true;
        if (t1 == null)
            return false;
        return isSubTree(t1, t2) || checkSubTree(t1.left, t2) || checkSubTree(t1.right, t2);
    }

    public boolean isSubTree(TreeNode t1, TreeNode t2){
        if (t2 == null)
            return true;
        if (t1 == null)
            return false;
        if (t1.val != t2.val)
            return false;
        return isSubTree(t1.left,t2.left) && isSubTree(t1.right,t2.right);
    }
}
```