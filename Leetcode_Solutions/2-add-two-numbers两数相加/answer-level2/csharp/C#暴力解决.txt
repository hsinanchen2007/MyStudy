### 解题思路
从两个链表的头节点开始，将两链表中对应位置数字与进位值之和模10得到结果为链表中对应位置的值，设置一个进位值，其数值等于两链表中对应位置数字相加除以10。

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
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        ListNode l3 = new ListNode(0);
        ListNode l4 = l3;
        int i = 0;
        while(l1 != null || l2 != null || i != 0)
        {
            ListNode l5 = new ListNode(0);
            if (l1 != null && l2 != null)
            {
                l5.val = (l1.val + l2.val + i) % 10;
                i = (l1.val + l2.val + i) /10;
            }
            else if(l1 != null)
            {
                l5.val = (l1.val + i) % 10;
                i = (l1.val + i) /10;
            }
            else if(l2 != null)
            {
                l5.val = (l2.val + i) % 10;
                i = (l2.val + i) /10;
            }
            else
            {
                l5.val = i;
                i = 0;
            }
            l4.next = l5;
            l4 = l5;
            if (l1 != null)
                l1 = l1.next;
            if (l2 != null)
                l2 = l2.next;
        }
        return l3.next;
    }
}
```