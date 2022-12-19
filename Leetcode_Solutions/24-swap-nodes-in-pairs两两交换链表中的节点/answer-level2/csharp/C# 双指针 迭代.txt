### 解题思路
定义 `first` 和 `second` 指针分别代表每次交换时的第一个和第二个节点。此外，还需要一个辅助的节点 `pre` 指向 `first`，它的作用是为了连接 `first` 和 `second` 交换后的结果，使之成为完整的链表，而不会断开。所以这三个节点的默认的顺序是: `pre` -> `first` -> `second`。

交换的逻辑是：
1. 第一个节点的 `next` 指向第二个节点的 `next`，如 1->3（3是2的next)
2. 第二个节点的 `next` 指向第一个节点，如 2->1，此时结果是 2->1->3；
3. 将 `pre` 节点的 `next`指向上面子链表的头结点，也即 `second`

交换完成后，要向下一组出发：
1. 更新 `pre` 为 `first`，也即本组最后一个，也是下一组之前的结点；
2. 更新 `first`（当前组的最后节点）为它的下一个节点（下一组的第一个节点）；
3. 如果`first`更新后不为空，则更新 `second` 为 `first.next`。


### 代码

```csharp
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode SwapPairs(ListNode head) {
        if(head == null || head.next == null)
        {
            return head;
        }

        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode pre = dummy;
        ListNode first = head;
        ListNode second = head.next;
        while(first != null && second !=null)
        {
            first.next = second.next;
            second.next = first;
            pre.next = second;

            pre = first;
            first = first.next;
            if(first != null )
            {
                second = first.next;
            }
        }

        return dummy.next;
        
    }
}
```