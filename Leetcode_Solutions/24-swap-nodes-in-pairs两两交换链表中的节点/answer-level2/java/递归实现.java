#####递归实现代码
```
public ListNode swapPairs(ListNode head) {
    if(head == null || head.next == null){//递归判断条件，如果无结点或者只有一个结点直接返回
        return head;
    }
    /*取出前两个结点*/
    ListNode first = head;
    ListNode second = head.next;
    /*head指向新的链表*/
    head = second.next;
    /*前两个结点交换位置*/
    second.next = first;
    /*head链表的结果链接到前两个结点链表后面*/
    first.next = swapPairs(head);
    /*返回结果*/
    return second;
}
```
