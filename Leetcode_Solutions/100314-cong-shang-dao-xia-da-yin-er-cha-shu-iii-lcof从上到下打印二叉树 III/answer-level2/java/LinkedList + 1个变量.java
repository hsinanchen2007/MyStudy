顺带一提这道题就是leetcode的[103题](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/)

# 代码
```java
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new LinkedList<>();
        if (root == null)
            return res;
        LinkedList<TreeNode> node_list = new LinkedList<>();
        node_list.add(root);
        int size = 1;
        boolean reverse = false;
        while (true) {
            ArrayList<Integer> temp = new ArrayList<>(size);
            if (reverse) {
                reverse = false;
                while (--size > -1) {
                    TreeNode temp_node = node_list.removeLast();
                    temp.add(temp_node.val);
                    if (temp_node.right != null)
                        node_list.addFirst(temp_node.right);

                    if (temp_node.left != null)
                        node_list.addFirst(temp_node.left);
                }
            } else {
                reverse = true;
                while (--size > -1) {
                    TreeNode temp_node = node_list.removeFirst();
                    temp.add(temp_node.val);
                    if (temp_node.left != null)
                        node_list.addLast(temp_node.left);

                    if (temp_node.right != null)
                        node_list.addLast(temp_node.right);
                }
            }
            res.add(temp);
            if ((size = node_list.size()) == 0)
                return res;
        }
    }
}
```
