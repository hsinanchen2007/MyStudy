顾名思义，将链表反转。如果有环，则一定会再次走到头结点；如果没环，就是正常反转操作；

容易理解容易写，但会破坏源数据。

执行用时 : 1 ms, 在所有 Java 提交中击败了92.72%的用户

内存消耗 : 40.2 MB, 在所有 Java 提交中击败了41.39%的用户

```
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode node = head;
        ListNode pre = null;
        while (node != null) {
            ListNode temp = node.next;
            node.next = pre;
            pre = node;
            node = temp;
            if (node == head) {
                return true;
            }
        }
        return false;
    }
}
```
