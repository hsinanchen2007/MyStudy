1. 双栈——借鉴前序遍历思路：按照“根-右-左”的前序遍历方式入栈，出栈的结果即后续遍历结果 
```
public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList();
        //s1：按照“根-右-左”的方式入栈
        Stack<Integer> s1 =new Stack<>();
        //s2：前序遍历的辅助栈
        Stack<TreeNode> s2 =new Stack<>();
        TreeNode node=root;
        while(!s2.isEmpty()||node!=null){
            while(node!=null){
                //根节点入栈
                s1.push(node.val);
                //所有的右孩子入栈
                s2.push(node);
                node=node.right;
            }
            //处理左子树
            if (!s2.isEmpty()){
                node=s2.pop();
                node=node.left;
            }
        }
        while (!s1.isEmpty()){
            list.add(s1.pop());
        }
        return list;
    }
```
2. 双栈——按照“根-右-左”的前序遍历方式入栈s2，出栈的结果即后续遍历结果。
```
public List<Integer> postorderTraversal(TreeNode root) {
           List<Integer> list = new ArrayList<>();
           if (root==null){
               return list;
           }
           Stack<TreeNode> s1 = new Stack<>();
           Stack<TreeNode> s2= new Stack<>();
           
           s1.push(root);
           while (!s1.isEmpty()){
               TreeNode node=s1.pop();
               s2.push(node);
               if (node.left!=null){
                   s1.push(node.left);
               }
               if (node.right!=null){
                   s1.push(node.right);
               }
           }
           while (!s2.isEmpty()){
               list.add(s2.pop().val);
           }
           return list;
    }
```

3. 单栈：栈存储访问过的节点，使用栈顶节点作为刚刚输出的节点，并初始化为根节点。对所有左子树节点压栈直至访问到最左叶子节点；输出最左叶子节点，弹出其父节点，处理父节点的右孩子，输出父节点，继续弹出节点重复以上操作。ps,判断一个节点是否需要处理的依据为：该节点为null或者该节点已经输出

```
public List<Integer> postorderTraversal(TreeNode root) {
           List<Integer> list = new ArrayList<>();
        if (root==null){
            return list;
        }
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        TreeNode top;
        while(!stack.isEmpty()){
            top = stack.peek();
            if (top.left!=null&&top.left!=root&&top.right!=root){
                stack.push(top.left);
            }else if (top.right!=null&&top.right!=root){
                stack.push(top.right);
            }else{
                root=stack.pop();
                list.add(root.val);
            }
        }
        return list;
    }
```
