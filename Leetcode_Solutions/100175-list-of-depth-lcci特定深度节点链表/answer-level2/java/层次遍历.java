# 代码
```java
class Solution {
    public ListNode[] listOfDepth(TreeNode tree) {
        if (tree == null) return new ListNode[0];
        LinkedList<TreeNode> queue = new LinkedList<>();
        LinkedList<ListNode> res = new LinkedList<>();
        queue.addLast(tree);
        int size = 1;
        while (true) {
            TreeNode head_treeNode = queue.removeFirst();
            if (head_treeNode.left != null) queue.addLast(head_treeNode.left);
            if (head_treeNode.right != null) queue.addLast(head_treeNode.right);
            ListNode head_listNode = new ListNode(head_treeNode.val);
            res.add(head_listNode);
            while (--size > 0) {
                head_treeNode = queue.removeFirst();
                head_listNode.next = (head_listNode = new ListNode(head_treeNode.val));
                if (head_treeNode.left != null) queue.addLast(head_treeNode.left);
                if (head_treeNode.right != null) queue.addLast(head_treeNode.right);
            }
            if ((size = queue.size()) == 0)
                return res.stream().toArray(ListNode[]::new);
        }
    }
}
```
