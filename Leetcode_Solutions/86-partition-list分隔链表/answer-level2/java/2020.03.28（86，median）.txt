### 解题思路
本题创建了**两个空链表**来存放两种情况的结点

- `head`结点**依次遍历**整个链表，将结点值比`x`**小**的元素接在`before`链后面，比`x`**大**的接在`after`链后面

- 最后一定要将大链表后的结点元素置为`null`，防止垃圾数据**导致链表循环**

- 将两个链表再合为新链，返回**带头结点后的链表信息**即可。

### 代码

```java []
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        // 创建两个空的带头结点分别链接比 x 小的和大的元素
        ListNode dummy_before = new ListNode(0);
        ListNode before = dummy_before;
        ListNode dummy_after = new ListNode(0);
        ListNode after = dummy_after;
        while (head != null) {           
            if (head.val < x) {
                // 比 x 小的就接在 before 结点后面
                before.next = head;
                before = before.next;                
            } else {
                // 比 x 大的就接在 after 结点后面
                after.next = head;  
                after = after.next;
            }
            head = head.next;
        }
        // 最后将后面大的链表的最后结点置为 null，防止发生循环
        after.next = null;
        // 前面小的链表最后一个结点连上后面大的链表的头结点的下一个节点
        before.next = dummy_after.next;
        return dummy_before.next;
    }
}
```