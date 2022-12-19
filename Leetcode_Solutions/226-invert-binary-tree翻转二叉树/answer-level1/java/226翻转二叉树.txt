1、递归：也是本题最自然的解法。建一棵新树result，将root的左子树作为result的右子树，将root的右子树作为result的左子树：

```
class Solution {
    public TreeNode invertTree(TreeNode root) {
        if(root ==null) return null;
        TreeNode result = new TreeNode(root.val);

        result.right = invertTree(root.left);
        result.left = invertTree(root.right);
     
        return result;
      
    }
}
```


2、迭代：利用一个堆栈，每次弹出一个节点时，对当前节点的左右子树进行互换。若存在子树，则将对应子树存入堆栈，等待其弹出后执行互换操作

```
class Solution {
    public TreeNode invertTree(TreeNode root) {
        if(root ==null) return null;
        
        Stack<TreeNode> stack = new Stack<TreeNode>();
        stack.push(root);

        while(!stack.isEmpty())
        {
            TreeNode now = stack.pop();
            TreeNode temp = now.left;
            now.left = now.right;
            now.right = temp;
            if (now.left != null) stack.push(now.left);
            if (now.right != null) stack.push(now.right);
        }

        return root;

    }
}
```
