### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int index = 0;
        int sum = l1.val + l2.val;
        if (sum == 0 && l1.next == null && l2.next == null) 
        {
            return new ListNode(0);
        }

        ListNode listNode = new ListNode(sum);

        if (sum >= 10) 
        {
            index = sum/10;
            sum = sum%10;
            listNode = new ListNode(sum);
        }

        if (l1.next == null && l2.next == null)
        {
            if (index > 0)
            {
                l1.next = new ListNode(0);
                l2.next = new ListNode(0);
            }
            else
            {
                return listNode;
            }
        }

        if (l1.next == null) 
        {
            l1.next = new ListNode(0);
        }

        if (l2.next == null) 
        {
            l2.next = new ListNode(0);
        }

        l1.next.val =  l1.next.val + index;
        listNode.next = addTwoNumbers(l1.next, l2.next);

        return listNode;
    }
}
```