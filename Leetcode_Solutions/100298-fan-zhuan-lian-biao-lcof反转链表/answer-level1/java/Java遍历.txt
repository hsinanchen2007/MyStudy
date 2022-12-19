
设置变量pre和temp
head : 1->2->3->null

while(head不为空)
1.将head.next赋值给temp     tmp 2->3
2.将head指向pre             head    1->null
3.将head赋值给pre           pre     1-> null
4.将temp赋值给head          head    2->3    

head为null，跳出循环，返回pre   null<-1<-2<-3
```
    public ListNode reverseList(ListNode head) {
        ListNode pre = null;
        ListNode temp = null;
        while (head != null) {
            temp = head.next;
            head.next = pre;
            pre = head;
            head = temp;
        }
        return pre;
    }
```