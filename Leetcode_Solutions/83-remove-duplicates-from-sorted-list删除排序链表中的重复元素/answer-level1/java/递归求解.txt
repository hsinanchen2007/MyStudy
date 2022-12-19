# 思路
如果链表为空就直接返回，不然就递归求解，如果当前节点和下一个节点的值不同就直接递归。如果值相同，就找到最后一个相同的值，比如1—>2->2->2->3，其中第二个数、第三个数、第四个数相同，当前指针指向第二个2，然后通过ListNode节点next指针，找到最后一个2，然后再调用递归函数即可。
```
public ListNode deleteDuplicates(ListNode head){
    if(head == null)
        return head;
    if(head.next != null && head.val == head.next.val){
        ListNode cur = head;
        while(cur.next != null && cur.next.val == head.val)
            cur = cur.next;
        head.next = deleteDuplicates(cur.next);
        return head;
    }else{
        head.next = deleteDuplicates(head.next);
        return head;
    }
}
```
