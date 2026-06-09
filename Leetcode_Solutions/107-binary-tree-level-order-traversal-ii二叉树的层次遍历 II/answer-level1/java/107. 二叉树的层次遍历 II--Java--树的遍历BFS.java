### 解题思路
[Leetcode-Java(200+题解，持续更新、欢迎star&留言&交流)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_107_levelOrderBottom.java)

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
    /**
     * 解题思路：
     * 树的问题就是遍历，本题用树的广度遍历（BFS）
     * BFS遍历依赖队列保存一层的节点
     *
     * @param root
     * @return
     */
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> retList = new ArrayList<>();
        if (root == null) return retList;
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);
        while (queue.peek() != null) {
            List<Integer> items = new ArrayList<>();
            List<TreeNode> treeList = new ArrayList<>();
            TreeNode poll = queue.poll();
            while (poll != null) {
                items.add(poll.val);
                if (poll.left != null) treeList.add(poll.left);
                if (poll.right != null) treeList.add(poll.right);
                poll = queue.poll();
            }
            if (!treeList.isEmpty()) {
                queue.addAll(treeList);
            }
            if (!items.isEmpty()) {
                retList.add(0, items);
            }
        }
        return retList;
    }
}
```