遍历的同时边添加，同129题，最后将所有总和加到sum即可

```
class Solution {
        public int sum = 0;
        public int sumRootToLeaf(TreeNode root) {
            helper(root,0);
            return sum;
        }
        public void helper(TreeNode root, int su){
            if(root==null){
                return;
            }
            int s = root.val+su*2;
            if(root.left == null && root.right == null) {
                sum = sum+s;
                return;
            }
            helper(root.left,s);
            helper(root.right,s);
        }
    }
```
