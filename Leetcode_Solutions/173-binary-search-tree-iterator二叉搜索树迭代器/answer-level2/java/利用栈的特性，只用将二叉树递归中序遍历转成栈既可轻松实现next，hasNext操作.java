```
private Stack<TreeNode> stack;

    public BSTIterator(TreeNode root) {
        stack = new Stack<>();
        inorderTraversal(root);
        System.out.println("已经转成栈");
    }
    /** 递归中序遍历 */
    private void inorderTraversal(TreeNode node){
        if(node!=null){
            if(node.right!=null){
                inorderTraversal(node.right);
            }
            stack.push(node);
            if(node.left!=null){
                inorderTraversal(node.left);
            }
        }
    }
    
    /** @return the next smallest number */
    public int next() {
        if(hasNext()){
            final TreeNode pop = stack.pop();
            return pop.val;
        }else{
            throw new IllegalStateException("没有next");
        }

    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return !stack.isEmpty();
    }
```

