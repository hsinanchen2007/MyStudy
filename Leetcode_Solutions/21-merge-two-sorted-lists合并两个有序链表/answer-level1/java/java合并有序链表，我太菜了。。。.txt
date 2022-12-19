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
        ListNode ans = new ListNode(-1);
        ListNode p = ans;
        while(l1 != null || l2 != null){
            if(l1 == null){
                p.next = l2;
                l2 = l2.next;
            }
            else if(l2 == null){
                p.next = l1;
                l1 = l1.next;
            }
            else if(l1.val >= l2.val){
                p.next = l2;
                l2 = l2.next;
            }
            else{
                p.next = l1;
                l1 = l1.next;
            }
            p = p.next;
        }
        return ans.next;
    }
}
```