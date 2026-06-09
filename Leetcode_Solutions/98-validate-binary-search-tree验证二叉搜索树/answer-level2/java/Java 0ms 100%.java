### 解题思路
官方题解优化了一下

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
    public boolean isValidBST(TreeNode root) {
        return help(root,null,null);
    }
    public boolean help(TreeNode root,Integer min,Integer max){
        if(root==null) return true;
        int val = root.val;
        if(min!=null && min>=val) return false;
        if(max!=null && max<=val) return false;
        return help(root.left,min,val) && help(root.right,val,max);
    }
}
```