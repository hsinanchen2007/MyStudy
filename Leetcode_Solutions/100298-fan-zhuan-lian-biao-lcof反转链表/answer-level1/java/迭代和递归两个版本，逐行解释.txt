### 解题思路
此处撰写解题思路

### 代码
迭代版本
```java
public ListNode reverseList(ListNode head) {
    ListNode pre = null;
    ListNode cur = head;
    while (cur != null) {
        //因为我们要往后移，所以要先保存cur的后一个，因为cur即将指向pre
        ListNode temp = cur.next;
        cur.next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}
```


递归版本
```java
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        //自顶向下，把head的后面的头传进去翻转，得到的是翻转链表的尾巴，后面链表翻转完的尾巴就是head.next
        ListNode tail = reverse(head.next);
        //翻转最后一个head。由于链表翻转完的尾巴就是head.next，要让head变为最后一个，那就是head.next.next = head
        head.next.next = head;
        //别忘了当前的头现在得指向null
        head.next = null;
        return tail;
    }
}
```