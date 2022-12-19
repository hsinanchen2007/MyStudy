    1. 在[https://leetcode-cn.com/problems/binary-tree-level-order-traversal/](二叉树的层次遍历))改动了下
```
    private static List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> lists = new ArrayList<>();
        add(lists, 0, root);
        return lists;
    }
    private static void add (List<List<Integer>> lists, int index, TreeNode node) {
        if (null == node) {
            return;
        }
        if (lists.size() == index) {
            lists.add(new ArrayList<>());
        }
        if ((index+1)%2 == 0) {
            lists.get(index).add(0, node.val);
        } else {
            lists.get(index).add(node.val);

        }
        if (null != node.left) {
            add(lists, index+1, node.left);
        }
        if (null != node.right) {
            add(lists, index+1, node.right);
        }
    }
```

