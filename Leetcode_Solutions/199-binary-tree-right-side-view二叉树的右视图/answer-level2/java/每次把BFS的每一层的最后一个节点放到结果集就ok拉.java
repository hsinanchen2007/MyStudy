```
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        
        if (root == null) return new ArrayList();

        Queue<TreeNode> queue = new LinkedList();
        // 把头结点放入
        queue.add(root);
        // 用来保存结果集
        List<Integer> list = new ArrayList();
        while(!queue.isEmpty()) {

            int size = queue.size();

            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                // 广搜的最后一个节点
                if (i == size -1) {
                    list.add(node.val);
                }
                if (node.left != null) {
                    queue.add(node.left);   
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
        }
        return list;
    }
}
```
