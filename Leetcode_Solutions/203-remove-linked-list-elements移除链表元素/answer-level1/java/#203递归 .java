
# 递归
```
 public ListNode removeElements(ListNode head, int val) {
        if(head == null)
            return null;
        head.next = removeElements(head.next,val);
        return head.val == val ? head.next : head;
 }
```
# 添加dummy节点
```
 public ListNode removeElements(ListNode head, int val) {

        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;

        ListNode prev = dummyHead;
        while(prev.next != null){
            if(prev.next.val == val)
                prev.next = prev.next.next;
            else
                prev = prev.next;
        }

        return dummyHead.next;
    }
```



