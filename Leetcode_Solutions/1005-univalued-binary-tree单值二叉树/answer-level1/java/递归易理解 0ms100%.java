```
class Solution {
        Integer num = null;
        public boolean isUnivalTree(TreeNode root) {
            if(root == null)return true;
            if(num == null)num = root.val;
            if(root.val!=num)return false;
            return isUnivalTree(root.left) && isUnivalTree(root.right);
        }
    }
```
