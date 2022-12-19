### 解题思路
暴力法时间复杂度O(n*m)，空间复杂度O(1)，利用哈希表时间复杂度O(n+m)，空间复杂度O(n)。而用双指针则可以得到进一步的优化使时间复杂度O(n+m)，空间复杂度O(1)。
暴力法和哈希表的方法可直接得出，至于如何得到双指针的方法，我们需要思考的是在常数空间复杂度下得到线性的时间复杂度，即没有了哈希表，遍历一次链表A遍历一次链表B。进一步思考，可以想到一个指针遍历完A再遍历B和遍历完B再遍历A走过的路程是相等的，都是两链表长度之和。若两个指针同时开始走这两条路，以相同的速度遍历链表中的结点，则会同时到达终点。
若两条链表不相交，则两个指针同时到达的终点都是空结点，走过的路程为两链表长度之和，且只有在终点时，它们才重合（都是null）。
若两条链表相交，设A链表长度为a，B链表长度为b，相交部分链表长度为i，则两个指针不用等到走完两链表长度之和，在那之前就能重合。当A走过的路程为$a+b-i$时，B走过的路程为$b+a-i$时，它们的下一步就会重合，开始一齐遍历相交部分。
综上，不相交，则重合结点为null；相交，则重合结点为相交部分的首结点。因此当两指针重合时返回当前结点便是答案。

### 代码

```java
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA == null || headB  == null)
            return null;
        ListNode pA = headA, pB = headB;
        while(pA != pB)
        {
            if(pA == null)  pA = headB;
            else            pA = pA.next;
            if(pB == null)  pB = headA;
            else            pB = pB.next;
        }
        return pA;        
    }
}
```