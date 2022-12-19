### 解题思路
链表真的很喜欢双指针

**思路分析**：两个链表，同时开始遍历，若有一个链表遍历完毕则指向另一个链表的头节点，在下一次循环再同步遍历，直至两指针相遇。【简单来说，我走完自己的路，走你的路，两条路穿插走，直至相遇】相遇时，两节点走过的路程相同。

**步骤**:
1. 对两个链表进行判空
2. 创建双指针
3. 利用while循环，两节点不相等时，分别对两指针指向的节点判空，空则指向另一链表的头节点，否则指向下一节点
4. 返回其中一个指针

说明：两链表不相交时，会出现同时指向为null的情况，则此时n1 == n2，返回null，满足题意。
另外看到还有利用栈和长链表优先的思路。可作为参考。

**时间复杂度**：O(M + N)
**空间复杂度**：O(1)

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
        ListNode n1 = headA;
        ListNode n2 = headB;
        
        while(n1 != n2){
            n1 = n1 == null ? headB : n1.next;
            n2 = n2 == null ? headA : n2.next;
        }
        return n1;
    }
}
```