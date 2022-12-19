### 解题思路
比较l1 和 l2 每一个元素的大小，小的拿出来放到结果里面，大的留下，拿走的指针下移一个，再比较，直到一个链表走空，然后剩下谁，谁就直接添加到结果链表里面。

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {

        if(l1 == null)
            return l2;
        else if(l2 == null)
            return l1;

        ListNode result = new ListNode(-1);
        ListNode p = result;

        while( l1 != null && l2 != null)
        {
            if(l1.val<=l2.val){
                result.next = l1;
                l1 = l1.next;
            }
            else if(l2.val <= l1.val)
            {
                result.next = l2;
                l2 = l2.next;
            }
            result = result.next;
        }

        if(l1 == null)
        {
            result.next = l2;
        }
        if(l2 == null)
        {
            result.next = l1;
        }

        return p.next;

    }
}
```