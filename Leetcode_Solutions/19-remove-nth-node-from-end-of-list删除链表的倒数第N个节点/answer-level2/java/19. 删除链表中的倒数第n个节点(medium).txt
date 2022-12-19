### 解题思路
1. 双指针滑动遍历链表一次
    a) 首先考虑特殊情况，链表中只有一个节点，如何删除这一个节点。
    b) 维护一个哑节点，此节点用于解决链表的边界问题。
    c) 维护两个指针start和end，分别作为“滑动窗口”两个边界。
    d) 两个节点起始位置都位于head节点。
    e) start指针走(n+1)个节点的长度，而后end节点开始走。形成了一个长度为n的“滑动窗口”。
    f) 当start节点到链表最后null的位置时，end节点刚好位于删除节点的前一个节点。
2. 遍历链表两次
    a) 首先考虑特殊情况，链表中只有一个节点，如何删除这一个节点。
    b) 维护一个哑节点，此节点用于解决链表的边界问题。
    c) 维护一个遍历节点p，第一次遍历得到链表的长度L。
    d) 第二次遍历到删除节点(L-n+1)的前一个节点(L-n)。
    e) 将节点(L-n+1)的next指向节点(L-n-1)。

[note]删除链表中节点的关键在于如何准确的找到被删除节点的前一个节点，并使其指针指向删除节点的下一个节点。
### 代码

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
        ListNode pre = new ListNode(0);
        pre.next = head;
        ListNode start = pre, end = pre;
        while(n != 0) {
            start = start.next;
            n--;
        }
        while(start.next != null) {
            start = start.next;
            end = end.next;
        }
        end.next = end.next.next;
        return pre.next;
    }
}

```
### 代码

```java

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public ListNode removeNthFromEnd(ListNode head, int n) {
    ListNode dummy = new ListNode(0);
    dummy.next = head;
    int length  = 0;
    ListNode first = head;
    while (first != null) {
        length++;
        first = first.next;
    }
    length -= n;
    first = dummy;
    while (length > 0) {
        length--;
        first = first.next;
    }
    first.next = first.next.next;
    return dummy.next;
}

```