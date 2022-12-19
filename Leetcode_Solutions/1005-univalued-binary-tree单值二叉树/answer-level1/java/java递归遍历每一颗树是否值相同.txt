### 解题思路
递归遍历每一颗树是否值相同

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
        if(root==null){
            return true;
        }

        boolean flag = true;
        if(root.left !=null){
            if(root.val != root.left.val){
                flag = false;
            }
        }

        boolean flag1 = true;
        if(root.right !=null){
            if(root.val != root.right.val){
                flag = false;
            }
        }

        boolean res = flag && flag1;
       
        return res && isUnivalTree(root.left) && isUnivalTree(root.right);

    }
}
```