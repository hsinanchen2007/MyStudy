### 解题思路
不要忘了head = head.next
执行用时 :
1 ms
, 在所有 Java 提交中击败了
99.54%
的用户
内存消耗 :
39.6 MB
, 在所有 Java 提交中击败了
100.00%
的用户
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
        ListNode l3 = new ListNode(-1);
        ListNode head = l3;
        while (l1 != null && l2 != null ){
            if (l1.val < l2.val){
                head.next =l1;
                head = head.next;
                l1 = l1.next;
            }else{
                head.next =l2;
                head = head.next;
                l2 = l2.next;
            }
        }
        while (l1 == null && l2 != null){
            head.next = l2;
            head = head.next;
            l2 = l2.next;
        }
        while (l1 != null && l2 == null){
            head.next = l1;
            head = head.next;
            l1 = l1.next;
        }
        return l3.next;
    }
}
```