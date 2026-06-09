### 解题思路
此处撰写解题思路
这个思路太牛逼了
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
       if (headA == null || headB == null) {
            return null;
        }
        ListNode preA=headA;
        ListNode preB=headB;
        
        while (true){
            if (headA==null&&headA==headB){return null;}
            if (headA==null){headA=preB;}
            if (headB==null){headB=preA;}
            if (headA==headB){return  headA;}
            headA=headA.next;
            headB=headB.next;
        }
    }
}
```