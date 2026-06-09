### 解题思路
没啥可说的

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
    public void flatten(TreeNode root) {
        TreeNode tn = root;
        if(root == null)
            return;
        while(!(tn.left==null&&tn.right==null))
        {
            if(tn.left!=null)
            {
                TreeNode temp = tn.left;
                while(temp.right!=null)
                {
                    temp = temp.right;
                }
                temp.right = tn.right;
                tn.right = tn.left;
                tn.left = null;
                tn = tn.right;
            }
            else
            {
                tn = tn.right;
            }
        }
    }
}
```