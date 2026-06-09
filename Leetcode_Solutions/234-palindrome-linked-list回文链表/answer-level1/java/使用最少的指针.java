## 思路
本题其实就是反转链表的变形，可以在反转链表的基础上加一个 fast 指针就能解决问题。**大家可以先熟练掌握反转链表的非递归写法再来做这道题**，代码的前半部分就是反转链表的非递归写法，但是这里停止反转的条件是 `` fast == null || fast.next == null``，为了更清楚些，我来举个例子：

eg1: ``1 2 3 4 5``

``fast`` 的起点为 1，那么当 ``fast.val = 5`` 时，此时 ``cur.val = 3``，``pre.val = 2``，故当 ``fast != null``，我们需要将 ``cur`` 向后一位，然后 pre 和 cur 逐个进行比较即可；


eg2: `` 1 2 3 4``

fast 的起点为 1，那么当 ``fast = null`` 时，此时 ``cur.val = 3``，``pre.val = 2``，故此时可以直接 pre 和 cur 直接逐个比较。

## 代码
```java
class Solution {
        // 反转前半部分
        public boolean isPalindrome(ListNode head) {
        if(head == null) return true;
        ListNode fast = head;
        ListNode cur = head, pre = null;
        while(fast != null && fast.next != null) {
           // 这里的 cur 指针就是 slow 指针，充当了两个作用
           // 一个是快慢指针找中点，一个是反转链表，因为 cur 也是每轮循环走一步
           fast = fast.next.next;
           ListNode nextTemp = cur.next;
           cur.next = pre;
           pre = cur;
           cur = nextTemp;
        }
        if(fast != null) {
            cur = cur.next;
        }
        while(pre != null) {
            if(pre.val != cur.val) return false;
            pre = pre.next;
            cur = cur.next;
        }
        return true;
    }
}
```