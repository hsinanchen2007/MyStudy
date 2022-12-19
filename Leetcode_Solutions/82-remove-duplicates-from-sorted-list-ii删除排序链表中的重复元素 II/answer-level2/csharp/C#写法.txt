
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
    public ListNode DeleteDuplicates(ListNode head)
{
    ListNode guardNode = new ListNode(0);
    var preNode = guardNode;
    var curNode = head;
    
    while(curNode != null && curNode.next != null)
    {
        if(curNode.val != curNode.next.val)
        {
            preNode.next = curNode;
            preNode = preNode.next;
            curNode = curNode.next;
        }else
        {
            int val = curNode.val;
            while(curNode!= null && curNode.val == val)
            {
                curNode = curNode.next;
            }
        }
    }
    preNode.next = curNode;

    return guardNode.next;
}
}
```