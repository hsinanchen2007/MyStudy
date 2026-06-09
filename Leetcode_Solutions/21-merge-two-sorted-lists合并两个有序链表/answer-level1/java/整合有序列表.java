### 解题思路
迭代，依次加入哨兵结点中

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
        ListNode head = new ListNode(0);
        ListNode tmpNode = head;
        while(l1 != null && l2 != null){
            if(l1.val < l2.val){
                tmpNode.next = l1;
                l1 = l1.next;
            }else {
                tmpNode.next = l2;
                l2 = l2.next;
            }
            tmpNode = tmpNode.next;
        }
        tmpNode.next = l1 == null ? l2 : l1;
        return head.next;
    }
}
```