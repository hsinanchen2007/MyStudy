### 解题思路
为了节省内存使用,返回的ListNode复用l1的内存;还有一个思路可以选择复用l1、l2中最长的node,但是这种情况执行时间会加大。

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int i = 0;
        ListNode result = l1;
        ListNode last = null;
        while (l1 != null || l2 != null){
            int p1 = l1 == null ? 0 : l1.val;
            int p2 = l2 == null ? 0 : l2.val;
            if(l1 != null){
                last = l1;
            }
            if(l1 == null){
                last.next = new ListNode((p1 + p2 + i) % 10);
                i = (p1 + p2 + i) / 10;
                last = last.next;
                l2 = l2.next;
            }else {
                l1.val = (p1 + p2 + i) % 10;
                i = (p1 + p2 + i) / 10;
                l1 = l1.next;
                l2 = l2 == null ? null : l2.next;
            }
        }
        if(i > 0){
            last.next = new ListNode(i);
        }
        return result;
    }
}
```