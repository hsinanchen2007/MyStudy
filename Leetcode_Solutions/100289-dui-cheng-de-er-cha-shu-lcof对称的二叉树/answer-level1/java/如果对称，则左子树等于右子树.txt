### 解题思路
如果对称，则左子树等于右子树；右子树等于左子树

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
        return check(root,root);
    }

    public boolean check(TreeNode one,TreeNode two){
        if(one==null && two ==null){
            return true;
        }
        if((one==null &&two!=null)|| (two ==null&& one!=null)){
            return false;
        }
        return one.val==two.val &&check(one.left,two.right) && check(one.right,two.left);
    }
}
```