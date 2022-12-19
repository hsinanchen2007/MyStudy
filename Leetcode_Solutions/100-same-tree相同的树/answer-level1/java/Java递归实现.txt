有且只有当p和q的做左子树和右子树都是同一棵树，并且p和q的值都相等，则认为它是同一棵树

```
    class Solution {
        public boolean isSameTree(TreeNode p, TreeNode q) {
            if(p==null && q==null) {
                return true;
            } else if(p==null || q==null) {
                return false;
            } 
            return isSameTree(p.left, q.left) && isSameTree(p.right, q.right) && (p.val == q.val);
        }
    }
```

时间复杂度O(n)
