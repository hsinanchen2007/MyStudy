### 解题思路
[延续了降级版题目的思路](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/shi-yong-listbi-queuekuai-liao-1ms-by-cyq7on/)，正向访问，使用一个bool变量控制添加进列表时是正向还是逆向。
成绩：双一百。

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
    List<List<Integer>> res = new ArrayList<>();
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) {
            return new ArrayList<>(0);
        }
        List<List<Integer>> res = new ArrayList<>();
        List<TreeNode> queue = new ArrayList<>();
        queue.add(root);
        boolean b = true;
        int i = 0;
        while (i < queue.size()) {
            int size = queue.size();
            List<Integer> list = new ArrayList<>();
            int k = 0;
            for (; i < size; i++,k++) {
                TreeNode node = queue.get(i);
                if (b) {
                    list.add(node.val);
                }else {
                    list.add(queue.get(size - 1 - k).val);
                }
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
            b = !b;
            res.add(list);
        }
        return res;
    }


}
```