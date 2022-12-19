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
    public ListNode reverseList(ListNode head) {
        if(head==null||head.next == null) return head;
        ListNode l1 =null,l2 = head,l3 = head.next;
        while(l3!=null){
            l2.next = l1;
            l1 = l2;
            l2 = l3;
            l3 = l3.next;
        }
        l2.next = l1;
        return l2;

    }
}
```