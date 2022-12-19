### 解题思路
不会无限循环
当a+b==b+a时，hA和hB会同时等于null，返回null

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
        if(headA == null || headB == null) return null;
        ListNode hA = headA, hB = headB;
        while(hA!=hB){ //不会无限循环，他们会同时等于null
            hA = (hA==null)? headB:hA.next;
            hB = (hB==null)? headA:hB.next;
        }
        return hA;
    }
}
```