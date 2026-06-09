### 解题思路
使用快慢指针，慢指针每次走一步，快指针每次走两步

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
    public ListNode MiddleNode(ListNode head)
        {
            ListNode slow = head;
            ListNode fast = head;
            while (fast != null&& fast.next != null)
            {
                slow = slow.next;
                fast = fast.next.next;

            }

            return slow;
        }
}
```