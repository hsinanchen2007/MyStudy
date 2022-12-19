### 解题思路
不管是列表还是快慢双指针，效率和内存都是一样的
大家都写双指针，我也实现一下列表法

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
            List<int> mdn = new List<int>(new[] { head.val });
            ListNode result = new ListNode(0);
            result.next = head;
            while (true)
            {
                if (head.next == null)
                {
                    break;
                }
                head = head.next;
                mdn.Add(head.val);
            }
            for (int i = -1; i < mdn.Count / 2; i++)
            {
                result = result.next;
            }
            return result;
        }
    
}
```