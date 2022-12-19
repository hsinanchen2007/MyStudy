### 解题思路
先反转k个元素，再把第k+1个元素放到已经反转的k个元素之前，则k+1个元素被反转。
假设有元素：1->2->3->4->5
第一步结果：2->1->3->4->5
第二步结果：3->2->1->4->5
第三步结果：4->3->2->1->5
第四步结果：5->4->3->2->1，完成

时间复杂度O(n)

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
    public ListNode reverseList(ListNode head) {
        if (head == null) return null;

        ListNode start = head, end = head;
        ListNode current = head.next;
        ListNode tmp;

        while (current != null) {
            tmp = current.next;

            current.next = start;
            end.next = tmp;
            start = current;

            current = tmp;
        }

        return start;
    }
}
```