### 解题思路
判断头节点中是否需要删除，因为用了快慢指针。如果第一个结点是要删除的结点的话会漏解。
然后判断快指针值是否需要删除就可以了。

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
    public ListNode deleteNode(ListNode head, int val) {
        //判断链表是否为空
        if(head == null)
            return head;
        
        //删除链表中头节点等于val的
        while(head != null && head.val == val){
            head = head.next;
        }
        if(head == null)
            return head;
        
        ListNode fast = head.next;
        ListNode slow = head;

        while(fast != null){
            if(fast.val == val){
                slow.next = fast.next;
            }
            fast = fast.next;
            slow = slow.next;
        }

        return head;
    }
}
```