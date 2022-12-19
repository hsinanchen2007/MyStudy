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
    private int ans = 0;
    public int sumNumbers(TreeNode root) {
        if(root == null) return ans;
        if(root.left == null && root.right == null){
            ans += root.val;
        }else{
            if(root.left != null){
                root.left.val += root.val*10;
                sumNumbers(root.left);
            }
            if(root.right != null){
                root.right.val += root.val*10;
                sumNumbers(root.right);
            }
        }
        return ans;
    }
}
```