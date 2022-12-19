***怎么去理解递归？***
假设原有链表是：1->2->3->null
终止条件是：当链表为空或者链表只有一个节点返回原链表，例如 null 3->null 都返回原链表
递归体是：ListNode node = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return  node;
怎么理解呢？
    递归调用栈为： reverseList(1->2->3->null)   reverseList(2->3->null)  reverseList(3->null)
    栈顶返回 3->null ：栈此时为：reverseList(1->2->3->null)   reverseList(2->3->null)
    栈顶弹出调用reverseList(2->3->null)，此时相当于node = 3->null, head = 2
            head.next.next = head 相当于3指向2 3->2 
            head.next = null ,相当于 3->2->null
    同理reverseList(1->2->3->null)
```java
    //递归
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        ListNode node = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return  node;
    }
```
***非递归***
```java
    public ListNode reverseList(ListNode head) {
        ListNode pre = null;
        ListNode cur = head;
        while(cur != null){
            ListNode after = cur.next;
            cur.next = pre;
            pre = cur;
            cur = after;
        }
        return pre;//一定是返回pre，此时cur为null
    }
```
