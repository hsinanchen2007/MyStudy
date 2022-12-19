### 解题思路
本来想定义外部数组的，想着空间占用一定很销魂，就看题解写了下这个，官方题解有点难懂，一看图解版就明白了

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
    public ListNode ReverseList(ListNode head)
        {
            ListNode prev = null;
            ListNode curr = head;
            ListNode temp;
            while (curr != null)
            {
                temp = curr.next;
                curr.next = prev;

                prev = curr;
                curr = temp;
            }

            return prev;
        }
}
```