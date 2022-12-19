### 解题思路
执行用时 :
124 ms, 在所有 csharp 提交中击败了91.13%的用户
内存消耗 :
27 MB, 在所有 csharp 提交中击败了5.07%的用户
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
    int t1=0;
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2){
        ListNode list = new ListNode(0);
        if (l1 == null && l2 == null)
        {
            return list;
        }
        if (l1 == null) { l1 = new ListNode(0); }
        if (l2 == null) { l2 = new ListNode(0); }
        int sum = l1.val + l2.val + t1;
        t1 = 0;
        if (sum > 9)
        {
            t1 = sum / 10;
            list.val = sum % 10;
        }
        else
        {
            list.val = sum;
        }
        if (l1.next == null && l2.next != null) { l1.next = new ListNode(0); }
        if (l2.next == null && l1.next != null) { l2.next = new ListNode(0); }
        if (t1 > 0&& l1.next == null && l2.next == null) {
            l1.next = new ListNode(0);
            l2.next = new ListNode(0);
        }
        if (l1.next == null && l2.next == null)
        {
            return list;
        }
        else if (l1.next.val >0|| l2.next.val >0 || t1 > 0)
        {
            list.next = AddTwoNumbers(l1.next, l2.next);
        }
        else if (l1.next.val ==0 && l2.next.val ==0)
        {
            list.next = AddTwoNumbers(l1.next, l2.next);
        }
        return list;
    }
}
```