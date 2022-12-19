### 解题思路


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
        if(head==null) return null;
        ListNode pre =head;
        ListNode node=head;
        ListNode next=head.next;
        int i=0;
        while(next!=null){
            pre=node;
            node=next;
            next=node.next;
            node.next=pre;
            if(i==0){
                pre.next=null;
                i=1;
            }
        }
        return node;

    }
}
```