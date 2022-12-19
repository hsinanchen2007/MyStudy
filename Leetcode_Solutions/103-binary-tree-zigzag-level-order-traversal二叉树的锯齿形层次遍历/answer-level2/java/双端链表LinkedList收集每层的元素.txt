__粗体__层次遍历的时候，改变层级list的收集方式
```
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }
        List<List<Integer>> res = new ArrayList<>();
        //正常的层次遍历
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        //初始化，第一层是向右
        boolean toRight = true;
        while (!queue.isEmpty()) {
            //双端链表，收集每层的元素
            LinkedList<Integer> level = new LinkedList<>();
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                root = queue.poll();
                if (toRight) {
                    //从前往后插入，同addLast()
                    level.add(root.val);
                } else {
                    //从后往前插入
                    level.addFirst(root.val);
                }
                if (root.left != null) {
                queue.add(root.left);
                }
                if (root.right != null) {
                    queue.add(root.right);
                }
            }

            //修改收集方式的标志
            toRight = !toRight;
            //将本层集合加入结果集
            res.add(level);
        }
        return res;
    }
}
```
