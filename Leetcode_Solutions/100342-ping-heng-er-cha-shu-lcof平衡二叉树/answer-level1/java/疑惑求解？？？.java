### 解题思路
本身我是这样写的,就有用例不能通过，改成提交的就可以了。不解
if(root == null){
           return true;
       }
       
       isBalanced(root.left);
       isBalanced(root.right);

       if(Math.abs(Depth(root.left)-Depth(root.right)) <= 1){
           return true;
       }
       return false;

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

       if(Math.abs(Depth(root.left)-Depth(root.right)) > 1){
           return false;
       }
       return isBalanced(root.left) && isBalanced(root.right);
    }
    private int Depth(TreeNode root){
        if(root == null){
            return 0;
        }
        int left = Depth(root.left)+1;
        int right = Depth(root.right)+1;

        return left>right?left:right;
    }
}
```