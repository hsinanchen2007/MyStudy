### 解题思路
头插法

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
    public ListNode Partition(ListNode head, int x)
        {
           if (head == null)
            {
                return null;
            }
            ListNode cur = head;
            while (cur.next != null)
            {
                if (cur.next.val<x)
                {
                    ListNode nextNode = cur.next;
                    cur.next = nextNode.next;
                    nextNode.next = head;
                    head = nextNode;
                }
                else
                {
                    cur = cur.next;
                }
            }

            return head;
        }

}
```