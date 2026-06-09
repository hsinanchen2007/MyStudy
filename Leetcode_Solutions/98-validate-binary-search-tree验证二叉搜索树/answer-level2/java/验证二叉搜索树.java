递归
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

非递归
```
    public boolean isValidBST(TreeNode root) {
        Stack<TreeNode> stack = new Stack();
        TreeNode cur = root;

        long pre = Long.MIN_VALUE;
        while(cur != null || !stack.isEmpty()){
            while(cur != null){
                stack.push(cur);
                cur = cur.left;
            }
            cur = stack.pop();
            
            if(cur.val <= pre) 
                return false;
            pre = cur.val;
            
            cur = cur.right;
        }
        
        return true;
    }
```

