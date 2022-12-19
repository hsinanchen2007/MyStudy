### 解题思路

使用哑结点统一化操作，两个指针分别指向需要交换的节点的前一个节点。

先考虑通用情况，也就是结点数为偶数（且不为空）。

例如 `duumy -> 1 -> 2 -> 3 -> 4 -> null`，curr指针指向dummy（哑结点），next指针指向1，next指针把1的位置存下来了（`duumy(curr) -> 1(next) -> 2 -> 3 -> 4 -> null`），所以先把curr的next指向2，再想办法把1插到2后面（`duumy(curr) -> 2 -> 3 -> 4 -> null`，`next(1)`）。3的位置很好找（curr.next.next），把1的next指向3，再把2的next指向1，就完成了1次交换（`duumy(curr) -> 2 -> 1(next) -> 3 -> 4 -> null`）。这时候curr和next位置需要注意一下，因为接下来我们要交换3和4，所以要把curr放到3前面的位置，把next放到4前面的位置，所以把curr放到1的位置（即等于next），再把next往后走一位。

什么时候结束呢，可以看到当next到结尾的时候，也就是next等于null的时候结束，返回dummy.next即可。
 
当结点数为奇数时，比如 `duumy -> 1 -> 2 -> 3 -> null`，经过一轮交换后为 `duumy -> 2 -> 1(curr) -> 3(next) -> null`，就不能再进行交换操作了，这时候next.next为null，应该结束循环，所以循环终止条件为`next == null || next.next == null`，所以while里面的条件为`next != null && next.next != null`。



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
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode curr = dummy;
        ListNode next = curr.next;
        while (next != null && next.next != null) {
            curr.next = curr.next.next;
            next.next = curr.next.next;
            curr.next.next = next;
            curr = next;
            next = next.next;
        }
        return dummy.next;
    }
}
```