由于链表中数据已经排序，只要判断当前节点值是否跟下一个节点值是否相同就可以，如果相同，就讲下一个节点移除，就是将当前节点的next指向当前节点的next.next ，然后进行循环，如果当前节点下个节点不等于当前节点将当前节点引用指向下一个节点，空的list需要特殊处理；将头结点引用保存，用于方法返回；

```
public ListNode deleteDuplicates(ListNode head) {
        if(head==null){
            return head;
        }
        ListNode result = head;
        while(head.next!=null){
            if(head.next.val==head.val){
                head.next =head.next.next;
            }else{
                head = head.next;
            }
        }
        return result;
    }
```
