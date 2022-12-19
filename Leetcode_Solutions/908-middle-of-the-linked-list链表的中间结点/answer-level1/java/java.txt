### 解题思路
递归查找Listnode长度。四舍五入找出中间的值。
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
    public ListNode middleNode(ListNode head) {
        int reverse = reverse(head);

        int exec = (int) Math.ceil(reverse / 2);
        for (int i = 0; i < exec; i++) {
            head = head.next;
        }
        return head;
    }

    public static int reverse(ListNode node) {
        if (node.next != null) {
            return reverse(node.next) + 1;
        } else {
            return 1;
        }
    }
}
```