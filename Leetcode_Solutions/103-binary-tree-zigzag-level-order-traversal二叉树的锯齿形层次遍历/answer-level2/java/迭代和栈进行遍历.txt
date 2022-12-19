// 使用栈进行二叉树的锯齿层次遍历
// 不能使用队列的原因是因为,队列只能对单个节点的左右进行反转,但是不能对整层进行反转
// 同时使用栈也必须使用双栈的原因是,一层是正序,一层逆序,但是后加的会放到栈顶,而没办法区分层次

```
 // 使用 双栈交换实现树的层次遍历
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        Stack<TreeNode> tmp = new Stack<>();
        if (root == null){
            return result;
        }
        int flag = 1;
        stack.push(root);
        while (!stack.empty()){
            List<Integer> list = new ArrayList<Integer>();
            while (!stack.empty()){
                TreeNode node = stack.pop();
                list.add(node.val);
                if (flag == 1){
                    if (node.left != null) {
                        tmp.push(node.left);
                    }
                    if (node.right != null){
                        tmp.push(node.right);
                    }
                }else {
                    if (node.right != null){
                        tmp.push(node.right);
                    }
                    if (node.left != null) {
                        tmp.push(node.left);
                    }
                }
            }
            result.add(list);
            Stack<TreeNode> t = tmp;
            tmp = stack;
            stack = t;
            flag = -flag;
        }
      return result;
    }
```
