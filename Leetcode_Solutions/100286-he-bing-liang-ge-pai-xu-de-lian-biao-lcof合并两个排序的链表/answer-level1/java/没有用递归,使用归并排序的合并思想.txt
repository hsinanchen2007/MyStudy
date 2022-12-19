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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null){
            return l2;
        }else if(l2 == null){
            return l1;
        }
        ListNode newHead = new ListNode(-1);
        ListNode p = newHead;
        while (l1 != null && l2 != null){
            if (l1.val < l2.val){
                p.next = new ListNode(l1.val);
                l1 = l1.next;
            }else {
                p.next = new ListNode(l2.val);
                l2 = l2.next;
            }
            p = p.next;
        }

        while (l1 != null){
            p.next = new ListNode(l1.val);
            l1 = l1.next;
            p = p.next;
        }
        
        while (l2 != null){
            p.next = new ListNode(l2.val);
            p = p.next;
            l2 = l2.next;
        }
        return newHead.next;
    }
}
```