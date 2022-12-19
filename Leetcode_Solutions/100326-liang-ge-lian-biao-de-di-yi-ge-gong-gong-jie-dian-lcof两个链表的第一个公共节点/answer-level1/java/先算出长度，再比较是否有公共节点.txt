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
        int lenA = length(headA);
        int lenB = length(headB);
        while (lenA > lenB){
            lenA--;
            headA = headA.next;
        }
        
        while (lenA < lenB){
            lenB--;
            headB = headB.next;
        }
        
        while (headA != headB){
            headA = headA.next;
            headB = headB.next;
        }
        
        return headA;
    }

    private int length(ListNode node){
        int len = 0;
        while (node != null){
            len++;
            node = node.next;
        }
        return len;
    }
}
```