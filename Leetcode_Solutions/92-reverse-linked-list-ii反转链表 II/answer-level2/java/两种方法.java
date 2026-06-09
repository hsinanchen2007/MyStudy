## 思路:

思路一:

找到要翻转部分的链表,将其翻转,再与原链表拼接;

直接看代码注释.

思路二:

用三个指针,进行**插入**操作

例如:

`1->2->3->4->5->NULL, m = 2, n = 4`

将节点`3`插入节点`1`和节点`2`之间

变成: `1->3->2->4->5->NULL`

再将节点`4`插入节点`1`和节点`3`之间

变成:`1->4->3->2->5->NULL`

实现翻转的效果!

## 代码:

```python [1]
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        dummy = ListNode(-1)
        dummy.next = head
        pre = dummy
        # 找到翻转链表部分的前一个节点, 1->2->3->4->5->NULL, m = 2, n = 4 指的是 节点值为1
        for _ in range(m-1):
            pre = pre.next
        # 用双指针,进行链表翻转
        node = None
        cur = pre.next
        for _ in range(n-m+1):
            tmp = cur.next
            cur.next = node
            node = cur
            cur = tmp
        # 将翻转部分 和 原链表拼接
        pre.next.next = cur
        pre.next = node
        return dummy.next
```



```java [1]
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode pre = dummy;
        // 找到翻转链表部分的前一个节点, 1->2->3->4->5->NULL, m = 2, n = 4 指的是 节点值为1
        for (int i = 0; i < m - 1; i++) pre = pre.next;
        // 用双指针,进行链表翻转
        ListNode node = null;
        ListNode cur = pre.next;
        for (int i = 0; i < n - m + 1; i++) {
            ListNode tmp = cur.next;
            cur.next = node;
            node = cur;
            cur = tmp;
        }
        // 将翻转部分 和 原链表拼接
        pre.next.next = cur;
        pre.next = node;
        return dummy.next;
        
    }
}
```

思路二:

```python [2]
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        dummy = ListNode(-1)
        dummy.next = head
        pre = dummy
         # 找到翻转链表部分的前一个节点, 1->2->3->4->5->NULL, m = 2, n = 4 指的是 节点值为1
        for _ in range(m - 1):
            pre = pre.next
        # 用 pre, start, tail三指针实现插入操作
        # tail 是插入pre,与pre.next的节点
        start = pre.next
        tail = start.next
        for _ in range(n - m):
            start.next = tail.next
            tail.next = pre.next
            pre.next = tail
            tail = start.next
        return dummy.next
```



```java [2]
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode pre = dummy;
        // 找到翻转链表部分的前一个节点, 1->2->3->4->5->NULL, m = 2, n = 4 指的是 节点值为1
        for (int i = 0; i < m - 1; i++) pre = pre.next;
        // 用 pre, start, tail三指针实现插入操作
        // tail 是插入pre,与pre.next的节点
        ListNode start = pre.next;
        ListNode tail = start.next;
        for (int i = 0; i < n - m; i++) {
            start.next = tail.next;
            tail.next = pre.next;
            pre.next = tail;
            tail = start.next;
        }
        return dummy.next;
    }
}
```

