### 解题思路
很多同学都想到了这个方法，不过大多是用队列实现的，我最初使用队列时用了2ms，优化不下去了。再做之字形那道题目时回过来改为了List，发现快了1ms。
执行用时 :1 ms, 在所有 Java 提交中击败了98.05%的用户
内存消耗 :39.1 MB, 在所有 Java 提交中击败了5.19%的用户

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
        if (root == null) {
            return new ArrayList<>(0);
        }
        List<List<Integer>> res = new ArrayList<>();
        List<TreeNode> queue = new ArrayList<>();
        queue.add(root);
        int i = 0;
        while (i < queue.size()) {
            int size = queue.size();
            List<Integer> list = new ArrayList<>();
            for (; i < size; i++) {
                TreeNode node = queue.get(i);
                list.add(node.val);
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
            res.add(list);
        }
        return res;
    }
}
```