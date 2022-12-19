### 解法一：迭代
遍历链表，每访问一个结点，就将它的next指针反向，让其指向上一个结点。
需要注意的是头尾结点的处理，由于反转后的链表的末尾即原链表的起始，反转后链表末尾应指向null，因此不妨在反转前链表的起始添加一个null。

代码
```java
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode pre = null, current = head;
        while(current != null)
        {
            ListNode temp = current.next;
            current.next = pre;
            pre = current;
            current = temp;
        }
        return pre;
    }
}
```

### 解法二：递归
首先明确递归式是为了得到反转后链表的头结点，即原链表的最后一个结点。
然后再来看递归边界，结束递归的条件有两个：
- 原链表头结点为null，则反转后也为null，直接返回head；
- 当前结点的下一个结点为null，则说明到达了原链表的最后一个结点，返回该结点作为反转后链表头结点。

求出头结点后，对当前结点作反转：`head.next.next = head; head.next = null;`
递归的每一层都返回之前求出的头结点直至结束整个递归过程。

代码
```java
class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null)   
            return head;
        ListNode first = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return first;
    }
}
```