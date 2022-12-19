### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    if(headA == null || headB == null)
        return null;
    ListNode p1 = headA;
    ListNode p2 = headB;
    int flag = 0;
    while(flag != 2)
    {
        p1 = p1.next;
        p2 = p2.next;
        if(p1 == null)
        {
            p1 = headB;
            flag++;
        }
        if(p2 == null)
        {
            p2 = headA;
            flag++;
        }
            
    }
    while(p1 != p2 && p1 != null && p2 != null)
    {
        p1 = p1.next;
        p2 = p2.next;
    }
    return p1;
    }
}
```