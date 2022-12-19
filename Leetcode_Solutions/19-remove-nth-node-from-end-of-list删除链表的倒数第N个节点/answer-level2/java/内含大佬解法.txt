给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list



### 解题思路

#### 两遍扫描
第一遍扫描获取长度，第二遍扫描找到被删除节点的前驱节点，然后删除节点


##### Python
```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        cur = head 
        length = 0
        while cur:
            length += 1
            cur = cur.next
        h = ListNode(0)
        h.next = head
        cur = h
        k = length - n
        while k > 0 and cur:
            cur = cur.next
            k -= 1
        cur.next = cur.next.next
        return h.next
```


##### Java
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode cur = head ;
        int length = 0;
        while(cur != null){
            length += 1;
            cur = cur.next;
        }    
        ListNode h = new ListNode(0);
        h.next = head ;
        cur = h;
        int k = length - n;
        while(k > 0 && cur != null){
            cur = cur.next;
            k -= 1;
        } 
        cur.next = cur.next.next;
        return h.next;
    }
}
```


#### 大佬解法
大佬通过两个指针，让第一个指针出发n步后，第二个指针继续出发。当第一个指针到达尾部后，第二个指针刚好能够到达被删除节点。

##### Python
```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if not head:
            return head
        if not head.next:
            return head.next
        fast, low = head, head
        while n:
            fast = fast.next
            n -= 1
        if not fast:
            return head.next
        
        while fast.next:
            fast = fast.next
            low = low.next
        node = low.next.next
        low.next = node
        return head
```


##### Java
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode slow = dummy, fast = dummy;
        while(n -- > 0) fast = fast.next;
        while(fast.next != null)
        {
            slow = slow.next;
            fast = fast.next;
        }
        slow.next = slow.next.next;
        return dummy.next;

        
    }
```