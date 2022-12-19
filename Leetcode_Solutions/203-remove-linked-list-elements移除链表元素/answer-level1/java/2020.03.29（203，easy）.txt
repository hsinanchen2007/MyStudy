### 解题思路
本题创建带头结点`dummy`可以不用单独考虑头结点的情况，统一思路的作用

- 定义前驱结点`pre`用于指向 **删除目标元素后** 的元素，防止丢链

- 定义当前移动结点`cur`来**找目标元素**进而将其删除

- 最后返回`dummy`结点的下一个结点即可。

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
    public ListNode removeElements(ListNode head, int val) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        // 定义链表的前驱结点
        ListNode pre = dummy;
        // 定义 cur 依次从 head 开始遍历寻找目标元素
        ListNode cur = head;
        while (cur != null) {
            if (cur.val == val) {
                pre.next = cur.next;
                cur = pre.next;
            } else {
                pre = cur;
                cur = cur.next; 
            }                       
        }
        return dummy.next;
    }
}
```