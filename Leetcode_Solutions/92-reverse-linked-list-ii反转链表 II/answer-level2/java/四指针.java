### 解题思路
四个指针分别为要反转链表的前驱和后驱，头结点和尾结点
特判一下m==1的情况

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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if(head == null || head.next == null || n == 1)return head;
        ListNode node = head;
        ListNode subHead = null;
        ListNode subTail = null;
        ListNode preHead = null;
        ListNode rearTail = null;
        for(int i = 1; i <= n; i++){
            if(i == n) subTail = node;
            if(i == m) subHead = node;
            if(m == 1){
                preHead = head;
            }else if(i == m - 1) preHead = node;
            node = node.next;
        }
        rearTail = node;
        ListNode cur = subHead;
        ListNode pre = rearTail;
        ListNode temp = null;
        while(cur != rearTail){
            temp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = temp;
        }
        if(m == 1) return pre;
        preHead.next = pre;
        
        return head;
    }
}
```