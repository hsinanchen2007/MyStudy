### 解题思路
获取1 2 3，然后2.next指向1，向前挪动1 和 2

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
        if(head==null||head.next==null){
            return head;
        }
        ListNode now = head.next;
        head.next = null;
        ListNode p = head;
        while (now!=null){
            ListNode next = now.next;
            now.next = p;
            p = now;
            now = next;
        }
        return p;
    }
}
```