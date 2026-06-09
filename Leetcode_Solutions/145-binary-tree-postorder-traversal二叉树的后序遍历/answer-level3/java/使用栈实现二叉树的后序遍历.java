# 使用两个栈
1. 申请一个栈，记为s1，然后将头节点压入s1中。
2. 从s1中弹出的节点记为cur，然后将cur的左孩子压入s1中，然后把cur的右孩子压入s1中。
3. 在整个过程中，每一个从s1中弹出的节点都放入第二个栈s2中。
4. 不断重复（2)和（3），直到s1为空
5. 从s2中弹出节点并打印，打印的顺序就是逆序操作

```
public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        if (root == null)
            return list;
        Stack<TreeNode> s1 = new Stack<>();
        Stack<TreeNode> s2 = new Stack<>();
        s1.push(root);
        while (!s1.isEmpty()) {
            TreeNode p = s1.pop();
            s2.push(p);
            if (p.left != null)
                s1.push(p.left);
            if (p.right != null)
                s1.push(p.right);
        }

        while (!s2.isEmpty())
            list.add(s2.pop().val);

        return list;
    }
```

# 使用一个栈
1. 申请一个栈stack，将头节点压入stack，同时设置两个变量h和c。在整个流程中， h代表最近一次弹出并打印的节点，c代表当前栈顶节点，初始令h等于头节点，c为null；
2. 每次令c等于当前栈定节点，但是不从stack中弹出节点，此时分为三种情况：
- 如果c的左孩子不为空，并且h不等于c的左孩子，也不等于c的右孩子，则把c的左孩子压入stack中。
- 如果1）不成立，并且c的右孩子不为空，并且h不等于c的右孩子，则把c的右孩子压入stack中。
- 如果1）和2）都不成立，那么从 stack中弹出c并打印，然后令h等于c。
3. 重复（2）。直到stack为空。
```
public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        if (root == null)
            return list;
        Stack<TreeNode> stack = new Stack<>();
        TreeNode tmp = root;
        TreeNode c = null;      //c当前栈顶节点
        TreeNode h = root;      //h代表最近一次打印出来的节点
        stack.push(tmp);
        while (!stack.isEmpty()) {
            c = stack.peek();
            if (c.left != null && c.left != h && c.right != h)
                stack.push(c.left);
            else if (c.right != null && c.right != h)
                stack.push(c.right);
            else {
                h = stack.pop();
                list.add(h.val);
            }
        }
        return list;
    }
```

