思路：将二叉树的下标存储到数组中，根节点下标为 1，左子树结点为 2 * i，右子树下标为 2 * i+1。
然后我们层次遍历，每次比较最大宽度值。具体实现见代码，简单移动。
![leetcode1.png](https://pic.leetcode-cn.com/5d45c8accc2f8ee854a788aecc8a3a0d2b029703993b606c018a0f8dda6202d9-leetcode1.png)

```
public int widthOfBinaryTree(TreeNode root) {
        if(root == null) return 0;
        Queue<TreeNode> q = new LinkedList<>();
        LinkedList<Integer> list = new LinkedList<>();
        q.offer(root);
        list.add(1);
        int res = 1;
        while (!q.isEmpty()) {
            int count = q.size();
            for(int i =count; i> 0; i--) {
                TreeNode cur = q.poll();
                Integer curIndex = list.removeFirst();
                if(cur.left != null) {
                    q.offer(cur.left);
                    list.add(curIndex * 2);
                }
                if(cur.right != null) {
                    q.offer(cur.right);
                    list.add(curIndex * 2 +1);
                }
            }
            // list 中 size 为 1 的情况下，宽度也为 1，没有必要计算。
            if(list.size() >= 2) {
                res = Math.max(res, list.getLast() - list.getFirst() + 1);
            }
        }

        return res;
    }
```
