```
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
       return level(root);
    }

 private List<List<Integer>> level(TreeNode root) {
        List<List<Integer>> ln = new ArrayList<>();
        if(null == root) {
            return ln;
        }

        Queue<TreeNode> q1 = new LinkedList<>();
        q1.offer(root);
        Queue<TreeNode> q2 = new LinkedList<>();
        while (!q1.isEmpty() || !q2.isEmpty()) {
            TreeNode node = null;
            List<Integer> l = new ArrayList<>();
            while (!q1.isEmpty()) {
                node = q1.poll();
                l.add(node.val);
                if (null != node.left) {
                    q2.offer(node.left);
                }
                if (null != node.right) {
                    q2.offer(node.right);
                }
            }

            if (null != node) {
                ln.add(l);
                node = null;
                l = new ArrayList<>();
            }

            while (!q2.isEmpty()) {
                node = q2.poll();
                l.add(node.val);
                if (null != node.left) {
                    q1.offer(node.left);
                }
                if (null != node.right) {
                    q1.offer(node.right);
                }
            }

            if (null != node) {
                ln.add(l);
            }
        }

        return ln;
    }
}
```
