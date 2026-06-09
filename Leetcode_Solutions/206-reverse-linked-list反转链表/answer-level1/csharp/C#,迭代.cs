### 解题思路
在修改.next指向之前，把原先的.next用个变量缓存，防止丢失。

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
        if (head == null)
            return head;

        var temp = head.next;
        var nhead = head;
        nhead.next = null;
        head = temp;
        while(head != null)
        {
            temp = head.next;
            head.next = nhead;
            nhead = head;
            head = temp;
        }
        return nhead;    
    }
}
```