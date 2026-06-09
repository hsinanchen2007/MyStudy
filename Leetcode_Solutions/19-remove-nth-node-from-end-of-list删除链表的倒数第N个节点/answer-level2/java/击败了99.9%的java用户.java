典型的双指针问题。更多链表快慢指针的问题[参考此文](https://blog.csdn.net/reed1991/article/details/54808720)

题目默认应该是n<=链表的长度，刚开始这么写的
```
public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode fast = head;
        ListNode slow = head;

        while (n-- > 0){
            fast = fast.next;
        }
        //为了找到要删除的节点的前一个节点，所以此处让fast.next!=null
        while (fast.next != null){
            fast = fast.next;
            slow = slow.next;
        }
        //此时head为倒数第n个节点的前一个节点。
        slow.next = slow.next.next;
        return head.next;
    }
```
但是这么写会有个问题，当n和链表长度一样时，会报空指针。
改进的写法如下。
```
public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode res = new ListNode(-1);
        res.next = head;
        ListNode fast = res;
        ListNode slow = res;

        while (n-- > 0){
            fast = fast.next;
        }
        //为了找到要删除的节点的前一个节点，所以此处让fast.next!=null
        while (fast.next != null){
            fast = fast.next;
            slow = slow.next;
        }
        //此时head为倒数第n个节点的前一个节点。
        slow.next = slow.next.next;
        return res.next;

    }
```
