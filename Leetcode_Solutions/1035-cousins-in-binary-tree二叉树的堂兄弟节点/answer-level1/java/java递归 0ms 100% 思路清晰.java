设置一个前节点变量pre，递归查找，当找到第一个节点时设dep为当前节点的深度，找到第二个节点时比较第一个节点的深度，同时通过前节点pre判断是否为同个父节点。

```
class Solution {
        Integer dep = null;
        TreeNode pre;
        public boolean isCousins(TreeNode root, int x, int y) {
            return helper(root, x, y,0);
        }

        public boolean helper(TreeNode root, int x, int y, int depth){
            if(root == null) return false;
            if(root.val == x || root.val == y){
                if(dep == null){
                    dep = depth;
                    return false;
                }else{
                    return (pre.left!=root && pre.right!=root) && depth == dep;
                }
            }
            if (dep==null) pre = root;
            return helper(root.left,x,y,depth+1) || helper(root.right,x,y,depth+1);
        }
    }
```
