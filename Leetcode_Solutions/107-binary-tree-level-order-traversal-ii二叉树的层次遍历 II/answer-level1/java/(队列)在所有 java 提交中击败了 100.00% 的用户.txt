### 解题思路
队列的方式，可以实现层级遍历，最主要的注意点就是两层循环，外层循环表示当前层

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }

        // 仍然采用队列的方式，从头开始处理，需要注意的是，怎么分层
        // 每次放入队列后，都将其所有的结果放入，再外循环就可以了
        Queue<TreeNode> queue = new LinkedList<>();

        queue.offer(root); // 先将根节点加入

        LinkedList<List<Integer>> ans = new LinkedList<>();

        while (!queue.isEmpty()) {
            // 获取当前层的总数
            int currLevelNums = queue.size();

            List<Integer> currLevelVals = new ArrayList<>();

            // currLevelNums肯定不是0
            for (int i = 0; i < currLevelNums; i++) {
                // 将队列中内容按照顺序取出，然后按照顺序放入每个节点的左子节点和右子节点
                TreeNode treeNode = queue.poll();
                if (treeNode.left != null) {
                    queue.offer(treeNode.left);
                }
                if (treeNode.right != null) {
                    queue.offer(treeNode.right);
                }
                currLevelVals.add(treeNode.val);
            }

            ans.addFirst(currLevelVals);
        }

        return ans;
    }
}
```