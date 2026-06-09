使用两个队列，在层序遍历的过程中，将从某队列poll出元素的左右子树，offer到另一个队列上，即每个队列任意时刻的所有元素，都是处于二叉树的同一层的。当两队列都为空时，循环结束。
```java []
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) return new ArrayList<>();
        Queue<TreeNode> a = new LinkedList<>();
        Queue<TreeNode> b = new LinkedList<>();
        a.offer(root);
        List<List<Integer>> res = new ArrayList<>();
        while (!a.isEmpty() || !b.isEmpty()) {
            List<Integer> list = new ArrayList<>();
            while (!a.isEmpty()) {
                TreeNode poll = a.poll();
                list.add(poll.val);
                if (poll.left != null) b.offer(poll.left);
                if (poll.right != null) b.offer(poll.right);
            }
            res.add(list);
            Queue<TreeNode> temp = a;
            a = b;
            b = temp;
        }
        return res;
    }
}
```
![图片.png](https://pic.leetcode-cn.com/34e394e38da5244f14c4f6a3701b8fb970f01c7e3fdeb023611dea1ba5d9e16e-%E5%9B%BE%E7%89%87.png)
