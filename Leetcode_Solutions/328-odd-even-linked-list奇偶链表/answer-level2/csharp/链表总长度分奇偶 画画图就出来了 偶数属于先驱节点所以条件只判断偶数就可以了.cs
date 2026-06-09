```
public class Solution {
    public ListNode OddEvenList(ListNode head) {
        if(head == null){
            return head;
        }

        ListNode firstNode = head;
        ListNode secondNode = head.next;
        ListNode node = secondNode;
        while(secondNode != null && secondNode.next != null ){
            firstNode.next = firstNode.next.next;
            firstNode = firstNode.next;
            secondNode.next = secondNode.next.next;
            secondNode = secondNode.next;
        }
        firstNode.next = node;
        return head;
    }
}
```
