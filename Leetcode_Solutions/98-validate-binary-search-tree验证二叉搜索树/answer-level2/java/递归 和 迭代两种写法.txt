主要利用 二叉搜索树 中序遍历的有序性，只需在遍历的过程中判断当前节点是否大于前一个节点即可

递归写法：
```
    long pre = Long.MIN_VALUE;
    public boolean isValidBST(TreeNode root) {
        if(root == null) return true;
        
        if (isValidBST(root.left)) {
            if (pre < root.val) {
                pre = root.val;
                return isValidBST(root.right);
            }
        }
        return false;
   }
```

非递归写法
```
    long pre = Long.MIN_VALUE;
    public boolean isValidBST(TreeNode root) {
        if(root == null) return true;
        Stack<TreeNode> stack = new Stack();
        TreeNode cur = root;

        long pre = Long.MIN_VALUE;
        while(cur != null || !stack.isEmpty()){
            while(cur != null){
                stack.push(cur);
                cur = cur.left;
            }
            cur = stack.pop();
            if(cur.val <= pre) return false;
            pre = cur.val;
            cur = cur.right;
        }
        
        return true;
   }
```