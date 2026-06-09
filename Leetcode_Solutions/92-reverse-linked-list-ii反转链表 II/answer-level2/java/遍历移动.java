### 解题思路
先定位待反转节点的前置节点prev。然后遍历待反转节点，依次把节点移到prev后面。

例如：
输入1->2->3->4->5->NULL, m = 2, n = 4，
处理过程为：
1. 定位prev指向1
2. 移动3到1后面，结果1->3->2->4->5
3. 移动4到1后面，结果1->4->3->2->5，结束

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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode dummy = new ListNode(Integer.MIN_VALUE);
        dummy.next = head;

        ListNode prev = dummy;
        for (int i = 1; i < m; i++) prev = prev.next;

        int reverseNum = n - m;
        ListNode last = prev.next, current = last.next;
        for (int i = 0; i < reverseNum && current != null; i++) {
            last.next = current.next;
            current.next = prev.next;
            prev.next = current;

            current = last.next;
        }

        return dummy.next;
    }
}
```