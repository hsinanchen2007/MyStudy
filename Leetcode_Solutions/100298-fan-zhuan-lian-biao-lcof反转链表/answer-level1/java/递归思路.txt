### 复杂度分析
时间复杂度：O(n)
空间复杂度：O(n)

### 解题思路
递归传递需要反转的结点及其前驱结点引用，当需要反转结点为 null 时，其前驱即为新的 head 结点，作为递归退出条件返回
递归回调时，再将结点重新连接至其前驱即可

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
        return reverse(head, null);
    }

    private ListNode reverse(ListNode node, ListNode pre) {
        if (node == null) {
            return pre;
        }
        ListNode head = reverse(node.next, node);
        node.next = pre;
        return head;
    }
}
```