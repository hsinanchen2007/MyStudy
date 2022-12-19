```java
/**
  * 如果是删除当前节点，需要维护上一个指针
  * 如果是删除下一个节点，只需记录头节点即可
 */
class Solution {
    public ListNode deleteNode(ListNode head, int val) {
        if(head == null) return null;
        if(head.val == val) return head.next;

        ListNode newHead = new ListNode(0);
        newHead.next = head;
        while(head.next != null){
            if(head.next.val == val){
                head.next = head.next.next;
                break;
            }
            head = head.next;
        }
        return newHead.next;
    }
}
```