### 解题思路
本题是对链表进行插入排序

- 定义两个指针`pre`和`end`从带头结点`dummy`开始，`pre`用来确定**插入位置的前驱**，`end`用来表示**已排序部分的最后一个元素**也是当前遍历结点的前驱

- 如果当前顺序符合要求则结点指针后移遍历下一个结点

- 如果需要改变顺序，则先用`tmp`指针**保存当前结点的后继**，方便找到下轮排序的起始位置，同时也**防止闭环**的产生

- 确定好需要移动的元素，应该先判断`pre`指针所在位置**是否为插入位置的前驱**，如果不是则向后移动直到满足要求

- 每经过一轮排序，记得要将“定位”指针**放到适当的位置**，最后返回`dummy`结点后面的元素即可。

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
    public ListNode insertionSortList(ListNode head) {
        // 创建带头结点赋初值为         最小值
        ListNode dummy = new ListNode(Integer.MIN_VALUE);
        dummy.next = head;
        ListNode pre = dummy;
        ListNode end = dummy;
        ListNode cur = head;
        while (cur != null) {
            // 如果是升序，则遍历下一个
            if (end.val < cur.val) {
                end.next = cur;
                end = cur;
                cur = cur.next;
            } else {
                // 先定义一个 tmp 指向 cur 下一个结点防止丢链
                ListNode tmp = cur.next;
                // 断开要排的元素
                end.next = tmp;
                // 从头判断找出合适的插入位置
                while (pre.next != null && pre.next.val < cur.val) {
                    pre = pre.next;
                }
                // 找到插入位置后直接将元素放进来
                cur.next = pre.next;
                pre.next = cur;
                // 随后将定位指针归为
                pre = dummy;
                cur = tmp;
            }
        }
        return dummy.next;
    }
}
```