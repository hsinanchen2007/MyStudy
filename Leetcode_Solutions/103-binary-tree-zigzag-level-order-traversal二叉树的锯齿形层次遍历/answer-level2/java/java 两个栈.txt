```
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if (root == null) return new ArrayList();
        Stack<TreeNode> stack1 = new Stack();
        Stack<TreeNode> stack2 = new Stack();
        stack1.push(root);
        List<List<Integer>> res = new ArrayList();
        int i = 1;
        while(!stack1.isEmpty() || !stack2.isEmpty()){
            List<Integer> item = new ArrayList();
            if (!stack1.isEmpty()){
                while (!stack1.isEmpty()){
                    TreeNode node = stack1.pop();
                    item.add(node.val);
                    if ((i & 1) == 0){
                        if (node.right != null){
                            stack2.push(node.right);
                        }
                        if (node.left != null){
                            stack2.push(node.left);
                        }
                    } else {
                        if (node.left != null){
                            stack2.push(node.left);
                        }
                        if (node.right != null){
                            stack2.push(node.right);
                        }
                    }
                }
            }else {
                while(!stack2.isEmpty()){
                    TreeNode node = stack2.pop();
                    item.add(node.val);
                    if ((i & 1) == 0){
                        if (node.right != null) {
                            stack1.push(node.right);
                        }
                        if (node.left != null){
                            stack1.push(node.left);
                        }
                    } else {
                        if (node.left != null){
                            stack1.push(node.left);
                        }
                        if (node.right != null) {
                            stack1.push(node.right);
                        }

                    }
                }
            }
            i++;
            res.add(item);
        }
        return res;
    }
```
