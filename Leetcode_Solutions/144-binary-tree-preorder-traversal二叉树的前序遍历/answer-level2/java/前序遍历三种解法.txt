```
    //方式1-递归
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> list=new ArrayList<Integer>();
        help(root,list);
        return list;
    }

    public void help(TreeNode node,List<Integer> list){
        if(node==null) return ;
        list.add(node.val);
        help(node.left,list);
        help(node.right,list);
    }
```

```
    //方式2--迭代 这种迭代不适用于中序和后序
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> list=new ArrayList<Integer>();
        if(root==null) return list;
        Stack<TreeNode> stack=new Stack<TreeNode>();
        stack.add(root);
        while(!stack.isEmpty()){
            TreeNode node=stack.pop();
            list.add(node.val);
            if(node.right!=null){
                stack.add(node.right);
            }
            if(node.left!=null){
                stack.add(node.left);
            }
        }
        return list;
    }
```

```
    //方式3--迭代  该迭代方式只需要将while循环中的三个模块颠倒即可用于中序和后序
    //先序->根左右    中序->左根右   后序->左右根
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> list=new ArrayList<Integer>();
        if(root==null) return list;
        Stack<TreeNode> stack=new Stack<TreeNode>();
        stack.add(root);
        HashSet<TreeNode> set=new HashSet<TreeNode>();
        while(!stack.isEmpty()){
            TreeNode node=stack.peek();
            //根
            if(!set.contains(node)){
                list.add(node.val);
                set.add(node);
            }
            //左子树
            if(node.left!=null && !set.contains(node.left)){
                stack.add(node.left);
                continue;
            }
            //右子树
            if(node.right!=null && !set.contains(node.right)){
                stack.add(node.right);
                continue;
            }
            stack.pop();
        }
        return list;
    }
```


