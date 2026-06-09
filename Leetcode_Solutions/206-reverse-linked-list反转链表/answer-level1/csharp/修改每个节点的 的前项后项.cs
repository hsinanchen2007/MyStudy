### 解题思路
修改每个节点的 的前项后项

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
    public ListNode ReverseList(ListNode head) {
         ListNode prev=null;
                ListNode curr=head;
                while(curr!=null)
                {
                    ListNode lntemp = curr.next;
                    curr.next = prev;
                    prev = curr;
                    curr = lntemp;
                }
                return prev;
    }
}
```