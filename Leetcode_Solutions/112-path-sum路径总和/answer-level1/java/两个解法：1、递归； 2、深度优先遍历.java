```
1、递归
class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if(null == root) {
            return false;
        } 
        if(null == root.left && null == root.right) {
            if(sum == root.val) {
                return true;
            } else {
                return false;
            }
        }
        boolean left = false;
        boolean right = false;
        if(null != root.left) {
            left = hasPathSum(root.left, sum-root.val);
        }
        if(null != root.right) {
            right = hasPathSum(root.right,sum-root.val);
        }
        return left || right;
    }
}
2、深度优先遍历
class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if(null == root) {
            return false;
        } 
        LinkedList<TreeNode> stack = new LinkedList<>();
        LinkedList<Integer> num_stack = new LinkedList<>();
        stack.push(root);
        num_stack.push(sum-root.val);
        while(!stack.isEmpty() && !num_stack.isEmpty()) {
            TreeNode cur = stack.pollLast();
            int pathDiff = num_stack.pollLast();
            if(cur.left == null && cur.right == null && pathDiff == 0) {
                return true;
            }
            if(null != cur.left) {
                stack.push(cur.left);
                num_stack.push(pathDiff-cur.left.val);
            }
            if(null != cur.right) {
                stack.push(cur.right);
                num_stack.push(pathDiff-cur.right.val);
            }
        }
        return false;
    }
}
```
