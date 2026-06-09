### 解题思路
此处撰写解题思路

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
    public int getHeight(TreeNode node){
        if(node == null){
            return 0;
        }
        else{
            int left = getHeight(node.left)+1;
            int right = getHeight(node.right)+1;
            return left>right?left:right;
        }
    }
    public boolean isBalanced(TreeNode root) {
        if(root == null){
            return true;
        }
        int left = getHeight(root.left);
        int right = getHeight(root.right);
        if(Math.abs(left - right)>1){
            return false;
        }
        else{
            return isBalanced(root.left) && isBalanced(root.right);
        }
    }
}
```