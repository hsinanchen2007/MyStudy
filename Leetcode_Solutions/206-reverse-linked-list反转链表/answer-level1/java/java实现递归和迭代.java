## 1、递归解法

逻辑是先找到第N个结点，然后通过N-1.next.next=N-1来改变第N个结点的指向。同时，将N-1.next赋值为空，以免第一个结点会造成循环链表。整个过程先找到第N个结点，然后在递归返回的过程实现。

代码：

```java
public ListNode reverseList(ListNode head) {
    if (head == null || head.next == null) return head;
    ListNode p = reverseList(head.next);
    head.next.next = head;
    head.next = null;
    return p;
}
```



## 2、迭代解法

prev->head->next，通过nextTemp记录next结点，然后实现prev<-head, 再赋值head=nextTemp.

代码：

```java
public ListNode reverseList(ListNode head) {
    ListNode prev=null;
    ListNode cur = head;
    while (cur!=null){
        ListNode nextTemp= cur.next;
        cur.next=prev;
        prev=cur;
        cur = nextTemp;
    }
    return prev;
}
```

