```
class Solution {
    public ListNode deleteNode(ListNode head, int val) {
        ListNode node = head;
        ListNode pre = head;
        if(head==null)
            return null;
        if(head.val==val)
            return head.next;
        while(node!=null){
            if(node.val==val){
                node=node.next;
                pre.next=node;
                break;
            }
            pre=node;
            node=node.next;
        }
        return head;
    }
}
```
