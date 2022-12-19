### 解题思路

双指针, 进行一次遍历, 设置一个哑节点作为头结点, 方便管理

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
        ListNode p = head;
        // 当前节点移动n位
        while(n > 0){
            p = p.next;
            n--;
        }
        // 设置一个哑节点
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode cur = head; // 当前节点
        ListNode prev = dummy; // 当前节点的前驱节点
        while(p != null){
            p = p.next;
            prev = cur;
            cur = cur.next;
        }
        if(prev.next != null){
            prev.next = prev.next.next;
        }
        return dummy.next;
    }
}
```