### 解题思路

循环, 每次翻转k个节点

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
    public ListNode reverseKGroup(ListNode head, int k) {
        if(k <= 1) return head;
        ListNode dummy = new ListNode(-1);
        dummy.next = head; // 链表哑节点
        // pre表示group的前驱节点, end表示group的最后一个节点
        ListNode pre = dummy, end = dummy;
        while(head != null){
            for(int i=0; i<k && end != null; i++){
                end = end.next;
            }
            if(end == null){
                return dummy.next;
            }
            // newStart表示下一个group的开始节点, 为了进行翻转, 需要断开节点
            ListNode newStart = end.next;
            end.next = null; 
            // 这一个group节点的开始节点为pre的后驱
            ListNode start = pre.next;
            // 变换之后, start就变成了最后一个节点, 返回的是group的头节点
            pre.next = reverseK(start);
            // start节点变为了尾节点, 指向下一个group的开始节点
            start.next = newStart;
            // pre节点则指向start上一步尾节点, end也是当前group的尾节点
            pre = start;
            end = start;
        }
        return dummy.next;
    }

    private ListNode reverseK(ListNode start){
        ListNode dummy = new ListNode(-1);
        dummy.next = start;
        ListNode pre = null;
        while(start != null){
            // 先保存后驱节点, 然后后驱指向pre, pre变为当前节点, start移动
            ListNode tmp = start.next;
            start.next = pre;
            pre = start;
            start = tmp;
        }
        // 返回pre节点, 表示反转的根节点
        return pre;
    }
}
```