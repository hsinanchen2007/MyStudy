参考102题[（二叉树的层次遍历）](https://leetcode-cn.com/problems/binary-tree-level-order-traversal)

在该题结果的基础上将索引为奇数的List<Integer>翻转即可。

```
public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> list = new ArrayList<>();
        if (root == null) return list;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int level = 0;
        while (!queue.isEmpty()) {
            list.add(new ArrayList<>());
            int width = queue.size();
            for (int i = 0; i < width; i++) {
                TreeNode poll = queue.remove();
                list.get(level).add(poll.val);
                if (poll.left != null) queue.add(poll.left);
                if (poll.right != null) queue.add(poll.right);
            }
            level++;
        }
        //翻转第二、第四...(索引为奇数)的list，就得到该题的结果
        for (int i = 0; i < list.size(); i++) {
            if (i%2 == 1)
                Collections.reverse(list.get(i));
        }
        return list;
    }
```
