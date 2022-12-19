### 解题思路
注意第一个节点是否满足删除条件，其他的情况比较简单

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
        if(head == null)
            return head;
        while(head.val == val){
            head = head.next;
            if(head == null)
                return null;
        }
            
        ListNode pre = head;
        ListNode res = head;
        head = head.next;
        while(head != null){
            if(head.val == val)
                pre.next = head.next;
            else
                pre = pre.next;
            head = head.next;
            
        }
        return res;
    }
}
```