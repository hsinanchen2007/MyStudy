先用BFS遍历树找到所有可能的结点，存入队列中，再递归判断即可
![image.png](https://pic.leetcode-cn.com/6e56d68bc59c53d09c48f233acb320e129a76059f5cac46559694e4ef6cf8bd2-image.png)

    Queue<TreeNode> queue = new ArrayDeque<>();
    public boolean isSubPath(ListNode head, TreeNode root) {
        ListNode realhead = head;
        init(root,head);
        return isSubPathHelp(head,queue.poll(),realhead);
    }
    
    private boolean isSubPathHelp(ListNode head,TreeNode root,ListNode realhead) {
        if (root == null) return false;
        if (head.val == root.val) {
            if (head.next == null) {
                return true;
            }
            return isSubPathHelp(head.next,root.left,realhead) || 
            isSubPathHelp(head.next,root.right,realhead) ||
            isSubPathHelp(realhead,queue.poll(),realhead);
        }
        return false;
    }

    private void init(TreeNode root,ListNode head) {
        if (root == null) return;
        if (root.val == head.val) {
            queue.add(root);
        }
        init(root.left,head);
        init(root.right,head);
        return;
    }