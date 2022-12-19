递归
```
    private List<Integer> ansList = new ArrayList();
    public List<Integer> inorderTraversal(TreeNode root) {
        solve(root);
        return ansList;
    }
    
    private void solve(TreeNode root){
        if(root == null) return ;
        solve(root.left);
        ansList.add(root.val);
        solve(root.right);
    }
```
迭代
```
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ansList = new ArrayList();
        Stack<TreeNode> stack = new Stack();
        TreeNode cur = root;
        
        while(cur != null || !stack.isEmpty()){
            while(cur != null){
                stack.push(cur);
                cur = cur.left;
            }
            cur = stack.pop();
            ansList.add(cur.val);
            cur = cur.right;
        }
        
        return ansList;   
    }
```
