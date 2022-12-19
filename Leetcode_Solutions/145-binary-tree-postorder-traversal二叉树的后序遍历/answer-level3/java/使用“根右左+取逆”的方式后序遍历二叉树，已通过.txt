后序遍历对应的（左右根），是否可以使用（根右左）的方式遍历完之后然后取逆序得到呢？ 

```
    public List<TreeNode> postOrderStack3(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        List<TreeNode> list = new LinkedList<>();
        TreeNode cur = root;
        while (cur != null || !stack.isEmpty()) {
            while (cur != null) {
                stack.push(cur);
                list.add(cur);
                cur = cur.right;
            }

            cur = stack.pop();
            cur = cur.left;
        }
        Collections.reverse(list);
        return list;
    }
```
