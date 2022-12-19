### 解题思路
遍历两个链表，一个链表到头之后，马上指向另一个链表的头部，这样，两条链表遍历到第一个相等(equals)的结点就是第一个相交结点

条件，我个人觉得要限制切换条件，每个链表到头之后，只有一次机会切换到另一个链表的头部。如果允许无限制切换，个人觉得会在两个链表不想交的情况下无限循环

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

        ListNode currentA = headA;
        ListNode currentB = headB;

        int exChangeA = 0;
        int exChangeB = 0;

        while(currentA != null && currentB != null){
            if(currentA.equals(currentB)){
                return currentA;
            }

            currentA = currentA.next;
            if(currentA == null && exChangeA < 1){
                currentA = headB;
                exChangeA ++;
            }

            currentB = currentB.next;
            if(currentB == null && exChangeB < 1){
                currentB = headA;
                exChangeB ++;
            }

        }

        return null;
        
    }
}
```