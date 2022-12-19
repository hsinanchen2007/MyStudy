//设置两个指针，fast指针先走K步，而slow指针从head开始。
//fast和slow 同时走，当fast到链表尾的时候，此时的slow指针指向的节点便是倒数第k个节点。
class Solution {
    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode fast = head;
        ListNode slow = head;
        for(int i = 0; i < k; i ++){
            fast = fast.next;
        }
        while(fast != null){
            slow = slow.next;
            fast = fast.next;
        }
        return slow;
    }
}