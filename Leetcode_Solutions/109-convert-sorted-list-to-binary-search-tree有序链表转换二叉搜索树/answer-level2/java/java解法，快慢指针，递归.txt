思路参考Leetcode108，每次选中间的结点作为root，链表要找出中间结点就需要设好头和尾，然后用快慢指针，一个指针走一步，一个指针走两步

class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        return buildTree(head, null);
    }

    TreeNode buildTree(ListNode start_node, ListNode stop_node){
        if(start_node!=stop_node){
            ListNode slow = start_node, fast = start_node;
            while(fast!=stop_node && fast.next!=stop_node){
                fast = fast.next.next;
                slow = slow.next;
            }
            TreeNode node = new TreeNode(slow.val);
            node.left = buildTree(start_node, slow);
            node.right = buildTree(slow.next, stop_node);
            return node;
        }
        return null;
    }
}