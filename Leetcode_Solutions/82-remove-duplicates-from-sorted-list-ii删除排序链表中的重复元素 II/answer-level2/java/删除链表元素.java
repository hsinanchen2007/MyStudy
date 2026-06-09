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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode first = new ListNode(0);
        first.next = head;
        ListNode p = first;
        ListNode left,right;
        while(p.next != null) {
            left = p.next;
            right = left;
            while(right.next!=null&&right.next.val==left.val){
                ListNode tmp = right;
                right = right.next;
                tmp = null;
            }
            if(left == right) p = p.next;
            else {
                p.next = right.next;
                right = null;
            }
        }
        return first.next;
    }
}
```