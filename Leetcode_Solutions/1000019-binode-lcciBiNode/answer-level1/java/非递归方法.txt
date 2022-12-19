```
public TreeNode convertBiNode(TreeNode root) {
        TreeNode head = null;
        TreeNode tail = null;
        
        TreeNode node = root;
        Stack<TreeNode> stack = new Stack();
        while(!stack.isEmpty() || node != null) {
            while(node != null) {
                stack.push(node);
                node = node.left;
            }
            node = stack.pop();
            if (head == null) {
                head = node;
                tail = node;
            } else {
                tail.right = node;
                tail = node;
            }
            tail.left = null;
            node = node.right;
        }
        
        return head;
    }
```
