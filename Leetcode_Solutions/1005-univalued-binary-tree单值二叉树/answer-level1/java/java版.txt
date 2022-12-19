### 解题思路
1 以根节点作为参照节点
2 递归遍历左右节点，让左右节点的值和根节点比较，如果有节点的值和根节点的值不相等则返回false，
否则返回true。

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
    public boolean isUnivalTree(TreeNode root) {
        if(root==null) return true;
        return helper(root,root.val);
    }
    public boolean helper(TreeNode root,int val){
        if(root==null) return true;
        if(root.val!=val) return false;
        return helper(root.left,val)&&helper(root.right,val);
    }
}
```