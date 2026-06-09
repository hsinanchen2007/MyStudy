### 解题思路
遍历列表找到目标区间，因此需要若干变量： 
`pre` 表示区间前的节点；
`start` 表示区间的第一个节点；
`end` 表示区间的最后一个节点；
`next` 表示区间之后的节点；

此外，定义一个通用的 `Reverse` 函数来反转指定头节点的链表。
当定位了上述节点之后，先将 `end`的下一个节点设置为空，然后，从 `start` 位置调用 Reverse函数，`pre.next`的值即为函数`Reverse`返回的值。此时，`start`成了区间的最后一个节点（即原来的`end`），将它的`next`指向刚才断开后的后面列表的第一节节点，也即 `next`。

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
    public ListNode ReverseBetween(ListNode head, int m, int n) {
        if(m >= n) return head;

        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode start = dummy.next;
        ListNode pre = dummy;
        ListNode end = null;        
        ListNode next = null;

        ListNode curr = dummy;
        
        int i = 1;
        while(curr.next != null)
        {
            if(i+1 == m)
            { 
                pre = curr.next;
                start = curr.next.next;
            }
            else if(i == n)
            {
                end = curr.next;
                next = curr.next.next;
            }            

            i += 1;            
            curr = curr.next;
        }

        end.next = null;

        pre.next = Reverse(start);
        start.next = next;

        return dummy.next;
    }

    private ListNode Reverse(ListNode head)
    {
        ListNode pre = null;
        ListNode curr = head;
        while(curr != null)
        {
            ListNode next= curr.next;

            curr.next= pre;
            pre = curr;
            curr = next;
        }

        return pre;
    }
}
```