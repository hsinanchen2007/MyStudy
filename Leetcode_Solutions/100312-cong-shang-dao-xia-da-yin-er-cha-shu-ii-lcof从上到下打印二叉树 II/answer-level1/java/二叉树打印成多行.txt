### 解题思路
此处撰写解题思路
按照广度优先遍历算法（BFS）层次遍历二叉树，按层次打印时，通过start,end两个变量来控制层次。
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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> list = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        List<Integer> floor = new ArrayList<>();
        if (root == null) {
            return new ArrayList<>();
        }
        int start = 0;
        int end = 1;
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            start++;
            if (node.left != null) {
                queue.add(node.left);
            }
            if (node.right != null) {
                queue.add(node.right);
            }
            floor.add(node.val);
            if (start == end) {
                end = queue.size();
                start = 0;
                list.add(floor);
                floor = new ArrayList<>();
            }
        }
        return list;
    }
}
```