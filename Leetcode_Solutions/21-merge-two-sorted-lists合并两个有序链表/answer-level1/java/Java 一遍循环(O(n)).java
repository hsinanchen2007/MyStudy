### 解题思路
当l1和l2都不是空的时候，每次比较l1和l2的值的大小，先把小的一方填入result即可。当任意一方为空的时候，如果另外一方还有节点，则另一方接入到结果的末尾。

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
        ListNode dummy = new ListNode(0);
        ListNode result = dummy;
        
        if (l1 == null) {
            return l2;
        }
        if (l2 == null){
            return l1;
        }
        
        while (l1 != null && l2 != null){
            if (l1.val <= l2.val){
                result.next = l1;
                l1 = l1.next;
            } else {
                result.next = l2;
                l2 = l2.next;
            }
            result = result.next;
        }

        if (l1 != null){
            result.next = l1;
        }
        if (l2 != null){
            result.next = l2;
        }
        
        return dummy.next;
    }
}
```