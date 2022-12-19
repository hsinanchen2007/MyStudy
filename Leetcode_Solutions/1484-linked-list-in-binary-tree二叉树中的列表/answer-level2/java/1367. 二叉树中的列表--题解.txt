遍历二叉树的每一个节点，若当前节点的val等于head的val时，判断以当前节点之后相连的节点是否能够组成head链表
```
class Solution {
    private boolean isSubPath;

    public boolean isSubPath(ListNode head, TreeNode root) {
        ArrayList<Integer> list = new ArrayList<>();
        while (head != null) {
            list.add(head.val);
            head = head.next;
        }
        preOrder(root,list);
        return isSubPath;
    }

    private void preOrder(TreeNode node, ArrayList<Integer> list) {
        if (node == null || isSubPath)
            return;
        //todo
        if (node.val == list.get(0))
            isSubPath(node,list);
        preOrder(node.left,list);
        preOrder(node.right,list);
    }
    class StackNode {
        private TreeNode node;
        private int index;
        StackNode(TreeNode node, int index) {
            this.node = node;
            this.index = index;
        }
    }

    private void isSubPath(TreeNode node, ArrayList<Integer> list) {
        if (list.size() == 1) {
            isSubPath = true;
            return;
        }
        Stack<StackNode> stack = new Stack<>();
        if (node.right != null)
            stack.push(new StackNode(node.right,1));
        if (node.left != null)
            stack.push(new StackNode(node.left,1));
        int index = 1;
        while (!stack.empty()) {
            StackNode stackNode = stack.pop();
            if (stackNode.node.val == list.get(stackNode.index)) {
                if (stackNode.index == list.size() - 1) {
                    isSubPath = true;
                    return;
                } else {
                    if (stackNode.node.right != null)
                        stack.push(new StackNode(stackNode.node.right,stackNode.index + 1));
                    if (stackNode.node.left != null)
                        stack.push(new StackNode(stackNode.node.left,stackNode.index + 1));
                }
            }
        }
    }
}
```
