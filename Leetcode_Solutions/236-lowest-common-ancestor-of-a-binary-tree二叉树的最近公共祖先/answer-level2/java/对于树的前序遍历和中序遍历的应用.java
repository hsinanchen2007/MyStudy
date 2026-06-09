

```
 /**
     * 自己写的中序遍历，本方法兼容了p 和 q 都不在或者只有一个在树中的情况，都返回 null
     */
    static class Solution7 {
        int LEFT_DONE = 1;
        int BOTH_DONE = 2;
        class Wrapper {
            TreeNode node;
            int status;
            public Wrapper(TreeNode node, int status) {
                this.node = node;
                this.status = status;
            }
        }
        public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
            TreeNode lca = null;
            boolean foundOne = false;
            Stack<Wrapper> stack = new Stack<>();
            Wrapper tmp = new Wrapper(root, LEFT_DONE);
            while (tmp.node != null || !stack.isEmpty()) {
                while (tmp.node != null) {
                    stack.push(tmp);
                    tmp = new Wrapper(tmp.node.left, LEFT_DONE);
                }
                Wrapper peek = stack.peek();
                if (peek.status == LEFT_DONE) {
                    if (peek.node == p || peek.node == q) {
                        if (foundOne) {
                            return lca;
                        } else {
                            lca = peek.node;
                            foundOne = true;
                        }
                    }
                    tmp = new Wrapper(peek.node.right, LEFT_DONE);
                    peek.status++;
                } else {
                    stack.pop();
                    if (lca == peek.node && !stack.isEmpty()) {
                        lca = stack.peek().node;
                    }
                }
            }
            return null;
        }
    }
```


```

    /**
     * 前序遍历，比上面的中序遍历好一点，提前检查是否已经全部找到两个节点，直接返回；中序遍历会在已经找到两个节点并且第二个节点还有子节点的情况下继续遍历
     */
    static class Solution8 {
        int LEFT_DONE = 1;
        int BOTH_DONE = 2;
        class Wrapper {
            TreeNode node;
            int status;
            public Wrapper(TreeNode node, int status) {
                this.node = node;
                this.status = status;
            }
        }
        public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
            boolean foundOne = false;
            TreeNode lca = null;
            Stack<Wrapper> stack = new Stack<>();
            Wrapper tmp = new Wrapper(root, LEFT_DONE);
            while (tmp.node != null || !stack.isEmpty()) {
                while (tmp.node != null) {
                    if (tmp.node == p || tmp.node == q) {
                        if (foundOne) {
                            return lca;
                        } else {
                            foundOne = true;
                            lca = tmp.node;
                        }
                    }
                    stack.push(tmp);
                    tmp = new Wrapper(tmp.node.left, LEFT_DONE);
                }
                Wrapper peek = stack.peek();
                if (peek.status == LEFT_DONE) {
                    //处理右子节点
                    tmp = new Wrapper(peek.node.right, LEFT_DONE);
                    peek.status++;
                } else {
                    //弹出，并看情况上移 lca
                    stack.pop();
                    if (peek.node == lca && !stack.isEmpty()) {
                        lca = stack.peek().node;
                    }
                }
            }
            return null;
        }
    }
```