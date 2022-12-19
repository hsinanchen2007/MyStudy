### 解题思路（详情见代码）
1. 计算长度并将尾节点指向头节点
2. 找到新的头节点和尾节点应该的位置
3. 返回结果

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
    public ListNode RotateRight(ListNode head, int k) {
        if(head == null || head.next == null || k==0)
        {
            return head;
        }
        //ListNode last = null;
        ListNode cur = head;
        int length = 1;
        while(cur.next != null)
        {
            cur = cur.next;
            length++;
        }
        if(k >= length)
        {
            k = k % length;
        }
        if(k == 0)
        {
            return head;
        }
        cur.next = head;
        int count = 1;
        ListNode newHead = null;
        ListNode newTail = null;
        var lastHead = head;
        while(count < length -k)
        {
            head = head.next;
            count++;
        }
        newTail = head;
        newHead = head.next;
        newTail.next = null;
        return newHead;
    }
}
```