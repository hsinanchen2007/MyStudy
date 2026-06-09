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
        public boolean isBalanced(TreeNode root) {
            if(root == null){
                return true;
            }
            int leftHeight = height(root.left);
            int rightHeight = height(root.right);
            if(leftHeight == -1 || rightHeight == -1 ||  leftHeight - rightHeight > 1 | leftHeight - rightHeight < -1){
                return false;
            }
            return true;
        }

        /**
         * -1 表示 不是平衡树
         * 0表示null
         * */
        private int height(TreeNode node){
            if(node == null){
                return 0;
            }
            int leftHeight = height(node.left);
            int rightHeight = height(node.right);
            if(leftHeight == -1 || rightHeight == -1 ||  leftHeight - rightHeight > 1 | leftHeight - rightHeight < -1){
                return -1;
            }
            return Math.max(leftHeight, rightHeight) + 1;
        }
    }
```