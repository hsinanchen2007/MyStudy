### 解题思路
此处撰写解题思路

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
        if(head==null) return null;
        ListNode preHead= new ListNode(0);
        preHead.next=head;
        ListNode index=preHead;

        while(index.next!=null){
            if(index.next.val==val){
                index.next=index.next.next;
                break;
            }
            index=index.next;
        }
        return preHead.next;
    }
}
```