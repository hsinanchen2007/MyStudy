```
//方式1--递归
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        help(root, res);
        return res;
    }

    public void help(TreeNode node, List<Integer> list) {
        if (node == null) return;
        help(node.left, list);
        list.add(node.val);
        help(node.right, list);
    }

    //方式2---迭代
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<Integer>();
        if (root == null) return list;
        Stack<TreeNode> stack=new Stack<TreeNode>();
        stack.add(root);
        HashSet<TreeNode> set=new HashSet<TreeNode>();
        while(!stack.isEmpty()){
           TreeNode node= stack.peek();

           if(node.left!=null && !set.contains(node.left)){
               stack.add(node.left);
               continue;
           }
           if(!set.contains(node)){
               list.add(node.val);
               set.add(node);
           }
           if(node.right!=null && !set.contains(node.right)){
               stack.add(node.right);
               continue;
           }

           stack.pop();
        }
        return list;
    }
```
