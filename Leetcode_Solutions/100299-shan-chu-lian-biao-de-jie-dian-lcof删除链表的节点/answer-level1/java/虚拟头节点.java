执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :38.4 MB, 在所有 Java 提交中击败了100.00%的用户
```
public ListNode deleteNode(ListNode head, int val) {
        if(head == null){
            return head;
        }
        ListNode pre = new ListNode(0);
        ListNode dummyHead = pre;
        pre.next = head; 

        while(head != null){
            if(head.val  == val){
                pre.next = head.next;
                break;
            }
            pre = head;
            head = head.next;
        }
        return dummyHead.next;
}
```
