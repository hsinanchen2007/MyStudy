![image.png](https://pic.leetcode-cn.com/03984f055bccf0e4ac7bdefc60fe3e0835ca44716d97acf2232a8dfc4fe432fe-image.png)

```
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> res = new ArrayList<Double>();
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        if(root == null) {
            return res;
        }
        queue.add(root);
        while(!queue.isEmpty()) {
            double sum = 0.0;
            int t = queue.size();
            for(int i = 0; i < t; i++) {
                TreeNode node = queue.poll();
                sum += node.val;
                if(node.left != null) {
                    queue.add(node.left);
                }
                if(node.right != null) {
                    queue.add(node.right);
                }
            }
            if(t > 0) {
                res.add(sum / t);
            }
        }
        return res;
    }
```
