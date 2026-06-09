### 解题思路
比较简单的方法

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
    public ListNode DeleteDuplicates(ListNode head) {
        ListNode curr = head;
        ListNode temp = head;

        while(curr != null)
        {
            if(curr.val == temp.val)
            {
                curr = curr.next;
                temp.next = null;
            }
            else
            {
                temp.next = curr;
                temp = temp.next;
                curr = curr.next;
            }
        }
        return head;
    }
}
```