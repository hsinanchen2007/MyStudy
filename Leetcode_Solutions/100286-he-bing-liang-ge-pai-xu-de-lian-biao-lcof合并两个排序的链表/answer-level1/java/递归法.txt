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
        if(l1 == null || l2 == null) return l1 == null ? l2 : l1;
        else {
            if(l1.val <= l2.val){
            l1.next = mergeTwoLists(l1.next,l2);
            return l1;
            }
            else {
                l2.next = mergeTwoLists(l1,l2.next);
                return l2;
            }
        }
    }
}
```
非常简单的递归法,效率也还是可以的.