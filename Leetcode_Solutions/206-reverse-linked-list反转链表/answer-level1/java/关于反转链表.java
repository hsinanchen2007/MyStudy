### 解题思路
其实核心就是要记录前后节点，反转指针之后还能找到下个节点


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
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        // 其实核心就是要记录前后节点，反转指针之后还能找到下个节点
        ListNode pre = null;
        ListNode current = head;
        ListNode reverseHead = null;
        while(current != null){
            ListNode next = current.next;
            if(next == null){
                reverseHead = current;
            }
            current.next = pre;
            pre = current;
            current = next;
        }
        return reverseHead;
    }
}
```