这道题的思路是将当前节点的左节点变成右节点，原右节点放到左节点的最右节点，一直重复这个过程。

第一，这种递归问题，首先要想明白什么时候跳出去，否则容易陷入死循环；
第二，原右节点放到左节点的最右节点真的需要嘛，并不是，我们完全可以用一个堆来做这件事

如果加上堆，那么退出的条件就是当前节点的左右节点都是空且堆也是空

`
    
    private static Stack<TreeNode> stack = new Stack();

    public void flatten(TreeNode root) {
        while (root.left != null || root.right != null || stack.size() > 0) {
            if (root.left != null) {
                root = dealLeft(root);
                continue;
            } else if (root.right != null) {
                root = dealRight(root);
                continue;
            }
            if (stack.size() > 0) {
                root = dealStack(root);
            }
        }
    }

    private TreeNode dealLeft(TreeNode root) {
        TreeNode node = root.right;
        root.right = root.left;
        root.left = null;
        if (node != null) {
            stack.add(node);
        }
        return root.right;
    }

    private TreeNode dealRight(TreeNode root) {
        return root.right;
    }

    private TreeNode dealStack(TreeNode root) {
        root.right = stack.pop();
        return root.right;
    }
`

