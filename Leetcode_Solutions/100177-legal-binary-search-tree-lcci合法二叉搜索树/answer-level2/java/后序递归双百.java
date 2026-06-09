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
    boolean flag = true;
    public boolean isValidBST(TreeNode root) {
        inorder(root);
        return flag;
    }
    
    public int[] inorder(TreeNode root){
        if(root == null || !flag)
            return null;
        int[] left = inorder(root.left);
        int[] right = inorder(root.right);
        if(left == null && right == null){
            int[] res = {root.val, root.val};
            return res;
        }
        if(left == null){
            if(right[0] <= root.val)
            {
                flag = false;
                return null;
            }
            right[0] = root.val;
            return right;
        }
        
        if(right == null){
            if(left[1] >= root.val){
                flag = false;
                return null;
            }
            left[1] = root.val;
            return left;
        }
        if(left[1] < root.val && right[0] > root.val){
            left[1] = right[1];
            return left;
        }
        
        flag = false;
        return null;
    }
}
```