### 解题思路
通过递归方式，遍历两个链表，处理过的链表就使用下一个节点进行遍历，保证所有的节点都能遍历到；写法比较简单。

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
        if (l1 == null) return l2;
        if (l2 == null) return l1;

        ListNode l3;
        if(l1.val < l2.val){
            l3 = new ListNode(l1.val);
            return handle(l1.next, l2, l3);
        }else {
            l3 = new ListNode(l2.val);
            return handle(l1, l2.next, l3);
        }
    }

    private ListNode handle(ListNode l1, ListNode l2, ListNode l3) {
        if (l1 == null && l2 == null) {
            return l3;
        } else if (l1 == null && l2 != null) {
            l3.next = new ListNode(l2.val);
            handle(l1, l2.next, l3.next);
        } else if (l1 != null && l2 == null) {
            l3.next = new ListNode(l1.val);
            handle(l1.next, l2, l3.next);
        } else {
            if (l1.val < l2.val) {
                l3.next = new ListNode(l1.val);
                handle(l1.next, l2, l3.next);
            } else {
                l3.next = new ListNode(l2.val);
                handle(l1, l2.next, l3.next);
            }
        }

        return l3;
    }
}
```