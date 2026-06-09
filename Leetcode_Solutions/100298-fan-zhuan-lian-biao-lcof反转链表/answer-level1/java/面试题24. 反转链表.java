### 解题思路
直接修改链表的指向，使链表的指向反向。

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
        ListNode node=head;
        ListNode pre=null;
        ListNode temp=null;
        while(node!=null){
          temp=node.next;
          node.next=pre;
          pre=node;
          node=temp;
        }
        return pre;
    }
}
```