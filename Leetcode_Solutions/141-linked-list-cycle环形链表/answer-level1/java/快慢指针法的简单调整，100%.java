### 解题思路
此处撰写解题思路

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
    public boolean hasCycle(ListNode head) {
        if(head == null || head.next == null) return false;
        ListNode slow = head;
        ListNode fast = head.next;
        while(slow != fast){
            if (fast != null && fast.next !=null){
                fast = fast.next.next;
                slow = slow.next;
            }else {
                return false;
            }
        }
        //说明快节点跟上慢节点，则是循环链表
        return true;
    }
}
```