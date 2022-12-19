根据已经插入层次数的奇偶来判断下一次插入的方向
```
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();

        if (root == null) {
            return result;
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        // 统计这一层的节点数
        while (!queue.isEmpty()) {
            // 该层的节点数量
            int levelCount = queue.size();
            ArrayList<Integer> sub = new ArrayList<>();
            
            // 遍历该层所有节点
            while (levelCount > 0) {
                TreeNode node = queue.poll();
                // 根据层次来判断该层节点的插入顺序
                if (result.size() % 2 == 0) {
                    sub.add(node.val);
                } else {
                    sub.add(0, node.val);
                }

                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
                levelCount--;
            }
            result.add(sub);
        }

        return result;
    }
}
```
[Github](https://github.com/hncboy/LeetCode)
