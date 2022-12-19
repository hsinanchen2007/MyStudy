### 解题思路
一、定义
链表头结点：Node0；链表开始入环节点:Node1；
慢指针和快指针第一次相遇的节点:Node2； 环的长度为L。
该问题是返回Node1节点。
二、分别从Node0 和 Node2同时同速度走，为何在Node1处相遇？
设Node0走到Node1为x步，Node1走到Node2为y步。
第一次快慢指针相遇时，
(1) 慢指针移动步数等于 x + y;
(2) 快指针比慢指针多环移动n圈，所以快指针移动步数等于 x + y + n*L;
(3) 又因为快指针移动次数是慢指针的2倍，所以有快指针移动步数为 2（x + y）;
由(2)(3) 可知，有等式 x + y + n*L = 2(x + y)，成立。
（4）化简得，x + y = n*L。
相遇时，快慢指针都位于Node2处，相当于从Node1开始走了y步了，由（4）只需要再走x步一定会走到Node1处。
三、如何判定走x步？
Node0到Node1也是x步，所以一个指针放在Node0,一个指针放在Node2处，
每次都向前走一步，一定会在Node1处相遇。
 
### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head == null) return head;
        ListNode slow = head;
        ListNode fast = head;
        while(slow != null && fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow.next;
                    fast = fast.next;
                }
                return slow;
            }
        }
        return null;
    }
    
}
```