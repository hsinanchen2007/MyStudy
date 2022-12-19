**方法一：数组**
```
class Solution {
    /**
    * 思路：
    * 使用数组存储链表节点，根据数组长度得到链表中间节点。
    */
    public ListNode middleNode(ListNode head) {
        ListNode[] A = new ListNode[100];
        int t = 0;
        while (head != null) {
            A[t++] = head;
            head = head.next;
        }
        return A[t / 2];
    }
}
```

**方法二：快慢指针法**
```
class Solution {
    /**
    * 思路：
    * (1) 使用快慢两个指针遍历链表，慢的每次走一步，快的每次走两步。
    * (2) 快指针遍历完链表的时候，慢指针指向链表的中间节点。
    */
    public ListNode middleNode(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
}
```
