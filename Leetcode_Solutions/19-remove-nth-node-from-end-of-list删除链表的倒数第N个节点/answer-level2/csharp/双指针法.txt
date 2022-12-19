### 解题思路
双指针法，快指针先走n-1次，然后快慢指针一起走，当快指针到达倒数第二个节点时，慢指针就到达了该删除节点的前一个节点，再执行删除操作就可以了。但是要注意两种特殊情况：1.当快指针先走了n-1步后成为了尾节点时，说明要删除的节点为头节点；2.当只有一个节点时，直接就删除了，返回null

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
    public ListNode RemoveNthFromEnd(ListNode head, int n) {
               if (head == null) return null;
            if (head.next == null) return null;
            ListNode fastnode = head;
            ListNode slownode = head;
            for (int i = 0; i < n-1; i++)
            {
                fastnode = fastnode.next;
            }
            if(fastnode.next == null)
            {
                head = head.next;
                return head;
            }
            while(fastnode.next.next != null)
            {
                fastnode = fastnode.next;
                slownode = slownode.next;
            }
            slownode.next = slownode.next.next;
            return head;
    }
}
```