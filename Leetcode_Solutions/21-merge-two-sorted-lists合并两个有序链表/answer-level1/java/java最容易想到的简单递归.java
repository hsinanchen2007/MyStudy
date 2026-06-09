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
        ListNode l3 = new ListNode();
        merge(l1, l2, l3);
        return l3.next;     
    }

    public void merge(ListNode l1, ListNode l2, ListNode l3) {
        if(l1 != null && l2 != null) {
            if(l1.val < l2.val) {
                l3.next = l1;
                merge(l1.next, l2, l3.next);
            } else {
                l3.next = l2;
                merge(l1, l2.next, l3.next);
            }
        } else if (l1 != null) {
            l3.next = l1;
        } else if (l2 != null) {
            l3.next = l2;
        } 
    }
}
```