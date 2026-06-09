### 解题思路
1.如果要删除的是head， 直接返回head.next
2.当前节点的下一个节点是要删除的节点， 直接让当前节点的下一个节点指向原本下一个的下一个。

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
        //iterate, if node.next.val == val, node.next = node.next.next;
        if(head == null) return null;
        ListNode dummy = head;
        while(dummy!=null && dummy.next!=null){
            if(dummy.val == val){
                return dummy.next;
            }

            if(dummy.next.val == val){
                dummy.next = dummy.next.next;
            }
            dummy = dummy.next;
        }
        return head;

    }
}
```