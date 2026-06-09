### 解题思路
添加虚头，从虚头遍历到要开始翻转的节点，利用遍历方式反转n-m+1个节点，把反转后的列表看作新的列表，然后插入回原列表。

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
    private ListNode lastNode = null;
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (m == n) {
            return head;
        }
        ListNode current = head, pre = new ListNode(0);
        pre.next = head;
        int i = 1;
        for (; i < m; i++) {
            pre = current;
            current = current.next;
        }
        ListNode tail = current, preNode = null, next = null;
        for (; i <= n; i++) {
            next = current.next;
            current.next = preNode;
            preNode = current;
            if (i <= n-1) {
                current = next;
            }
        }
        pre.next = current;
        tail.next = next;
        if (m == 1) {
            return pre.next;
        }
        return head;
    }


}
```