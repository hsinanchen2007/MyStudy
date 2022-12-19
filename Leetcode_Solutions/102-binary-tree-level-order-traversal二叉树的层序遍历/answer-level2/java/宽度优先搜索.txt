1. 在遍历过程中，使用last记录当前行的最有节点，使用nlast记录下一行的最有节点，初始时，令last等于头节点，令nlast等于null
2. 从队列弹出一个节点，将左孩子加入队列，令nlast等于左孩子，再将右孩子加入队列，令nlast等于右孩子。
判断当前弹出节点等不等于last，若相等的话，则换行。
1. 重复（2），直到队列为空

```
public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> lists = new ArrayList<>();
        if (root == null)
            return lists;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        //记录当前行的最右节点，初始值为头节点
        TreeNode last = root;
        //记录下一行的最右节点，，初始值为null
        TreeNode nlast = null;
        List<Integer> list = new ArrayList<>();
        while (!queue.isEmpty()) {
            //弹出一个节点
            TreeNode tmp = queue.poll();
            list.add(tmp.val);
            //压入左孩子
            if (tmp.left != null) {
                queue.offer(tmp.left);
                nlast = tmp.left;
            }
            //压入右孩子
            if (tmp.right != null) {
                queue.offer(tmp.right);
                nlast = tmp.right;
            }
            //判断当前弹出节点等不等于last，若等于，则换行
            if (tmp == last) {
                lists.add(list);
                list = new ArrayList<>();
                last = nlast;
            }
        }
        return lists;
    }
```


