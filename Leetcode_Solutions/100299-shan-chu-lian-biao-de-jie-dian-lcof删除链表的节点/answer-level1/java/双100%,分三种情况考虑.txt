### 解题思路
删除的节点在头部
删除的节点在中间
删除的节点在尾部
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
        if(head == null) return null;
        //删除的节点在头部
        if(head.val == val) return head.next;
        ListNode temp = head;
        while(temp != null){
            if(temp.val == val && temp.next != null){
                //删除的节点在中间
                temp.val = temp.next.val;
                temp.next = temp.next.next;
                return head;
            }else if(temp.next.val == val && temp.next.next == null){
                //删除的节点在尾部
                temp.next = null;
                return head;
            }
            temp = temp.next;
        }
        return head;
    }
}
```