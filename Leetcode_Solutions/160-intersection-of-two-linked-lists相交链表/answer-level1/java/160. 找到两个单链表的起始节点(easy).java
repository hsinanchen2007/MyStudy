### 解题思路
1. 对于两个单链表而言，首先考虑是否存在空链表。
2. 当两个单链表均不为空时，若不存在相交的节点。
3. 当两个单链表均为空时，找到相交的起始节点。
    a) 首先采用暴力检索，对于单链表A中每一个节点都遍历单链表B中的节点。(那么时间复杂度为O(mn),空间复杂度为O(1))
    b) 如果使用哈希表来存储，将单链表A每一个节点的地址存在哈希表中，然后检查B中的每一个节点是否在哈希表中。(时间复杂度为O(m+n),空间复杂度为O(m)或O(n))
    c) 使用双指针来分别遍历两个单链表，两个链表的头节点分别为headA和headB。(时间复杂度为O(m+n),空间复杂度为O(1))
        i) 创建指针pA和pB分别同时从单链表A和B的第一个节点开始向后遍历。
        ii) 假设单链表B的长度为4，单链表A的长度为6。当pB为null时，令pB为headA。此时pA和pB的位置相差2。
        iii) pA和pB继续保持向后遍历，当pA为null时，令pA为headB。此时pA和pB的位置依旧相差2。
        iV) pA遍历的长度等于pB遍历的长度等于a+c+b=b+c+a(c为A和B的公共部分)
[note]
    1. 空指针的返回值为null
    2. 两个指针遍历的节点的个数相同，故若存在节点的条件一定是pA==pB
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
        //check if exits empty lists
        if (headA == null || headB == null) {
            return null;
        }
        //build the pointers of A and B
        ListNode pA = headA;
        ListNode pB = headB;
        while (pA != pB) {
            //Iterate over the nodes in the list A and list B each other
            pA = pA.next;
            pB = pB.next;
            //when the value pA and pB are null at the same time, the two lists have no public node.
            if (pA == null && pB == null) {
                return null;
            }
            if (pA == null) {
                pA = headB;
            }
            if (pB == null) {
                pB = headA;
            }
        }
        return pA;
    }
}

```