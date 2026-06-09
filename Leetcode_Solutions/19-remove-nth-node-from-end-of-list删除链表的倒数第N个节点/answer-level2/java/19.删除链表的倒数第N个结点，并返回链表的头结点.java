### 解题思路
三个指针支撑功能：
1.虚拟结点指向head，始终在slow的前驱位置，作用：删除slow结点
2.slow为要删除的倒数第n个结点
3.quick为快指针，与slow相对距离为n
4.若slow==oldHead，即若即将删除头结点，则返回的新的头结点应为oldHead.next

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 *题目要求：1.删除倒数第n个结点   2.返回头结点
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head == null || head.next == null){
            return null;
        }
        ListNode oldHead = head;
        ListNode virtualHead = new ListNode(0);//虚拟结点
        virtualHead.next = head;
        ListNode slow = head;
        ListNode quick = head;
        while(quick.next != null){
            if(n==1){
                virtualHead = virtualHead.next;
                slow = slow.next;
            }else{
                n--;
            }
            quick = quick.next;
        }
        if(slow == oldHead){
            oldHead = slow.next;
        }
        virtualHead.next = virtualHead.next.next;
        
        return oldHead;
    }
}
```