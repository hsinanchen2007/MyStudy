### 解题思路

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
    public boolean isBalanced(TreeNode root) {
        if(root == null){
            return true;
        }
        if(Math.abs(high(root.left)-high(root.right))>1)
        return false;
        else{
            if(isBalanced(root.left)&&isBalanced(root.right))
            return true;
            else
            return false;
        }
    }
    public static int high(TreeNode t){
        if(t == null)
        return 0;
        return Math.max(high(t.left),high(t.right))+1;
    }
}
```