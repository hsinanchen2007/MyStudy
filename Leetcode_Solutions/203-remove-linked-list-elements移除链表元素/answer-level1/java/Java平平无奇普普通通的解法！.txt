### 解题思路
**添加头节点p！！！更方便处理原来第1个节点**
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
    public ListNode removeElements(ListNode head, int val) {
       ListNode p = new ListNode(0);
        p.next = head;
        while (p != null && p.next != null){
            if (p.next.val == val){
                if (p.next == head){
                    head = head.next;
                    p.next = head;
                    continue;
                }
                p.next = p.next.next;
                continue;
            }
            p = p.next;
        }
        return head;
    }
}
```