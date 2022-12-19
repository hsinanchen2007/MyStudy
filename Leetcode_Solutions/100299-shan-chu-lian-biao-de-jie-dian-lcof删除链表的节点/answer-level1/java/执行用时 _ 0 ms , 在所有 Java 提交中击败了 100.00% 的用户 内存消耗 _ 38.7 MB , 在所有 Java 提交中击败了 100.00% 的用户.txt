### 解题思路
本题如果找到了待删除节点，我们只要把该节点的前置节点指向重复节点的下一个结点即可，但特殊情况在于如果重复节点位于链表尾端，我们无法指向一个结点，因为尾端的下一个结点为空，java链表是找不到这个结点的，因此需要进行判断。

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
        ListNode prev = new ListNode(0);
        ListNode current = head;
        prev.next = head;
        if(head.val==val) {
            return head.next;
        }
        while(current!=null && current.val!=val) {
            prev = current;
            current = current.next;
        }
        if(current.next==null) {
            prev.next = null;
        }else {
            prev.next = current.next;
        }
        return head;

        
    }
}
```