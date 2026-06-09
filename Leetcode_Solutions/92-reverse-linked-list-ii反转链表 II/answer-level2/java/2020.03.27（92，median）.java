### 解题思路
本题使用**三个指针**`pre`，`start`，`tail`共同完成**链内反转**

- 首先**创建带头结点**`dummy`连在`head`前面，以保证操作的统一性

- 然后通过对`m`判断将`pre`指针循环往后**移动到操作位置之前**

- 然后通过`start`，`tail`指针完成**断链** + **接链**的过程，这样使得**最后断的结点可以接在新链的最前面**

- 最后将除了带头结点`dummy`外的**新链**返回即可。

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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        // 创建带头结点
        ListNode dummy = new ListNode(0);
        // 指向 head 结点
        dummy.next = head;
        // 创建 pre 也指向带头结点
        ListNode pre = dummy;
        for (int i = 0; i < m - 1; i++) {
            pre = pre.next;
        }
        // 创建两个结点进行删除再连接
        ListNode start = pre.next;
        ListNode tail = start.next;
        for (int i = 0; i < n - m; i++) {
            // 先把 tail 所指结点断开
            start.next = tail.next;
            // tail 结点连在 pre 的后面
            tail.next = pre.next;
            pre.next = tail;
            // 连好之后就可以再将 tail 指针重新指向 start 后面的结点
            tail = start.next;
        }
        // 最后把创建的头结点后面的内容返回即可
        return dummy.next;
    }
}
```