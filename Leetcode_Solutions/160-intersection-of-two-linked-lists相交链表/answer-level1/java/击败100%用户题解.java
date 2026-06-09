![WX20191107-000557@2x.png](https://pic.leetcode-cn.com/bf0bde1615a3a91ad505ff2c1e74b3efbaf6af85ecf9c6f3538491aaec6f15d5-WX20191107-000557@2x.png)

```
public static ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    /*如果有一个为null则返回null*/
    if (headA == null || headB == null) {
      return null;
    }
    /*计算2个链表的节点个数*/
    int countA = 0;
    int countB = 0;
    ListNode iterA = headA;
    ListNode iterB = headB;
    /*遍历计算2个链表的节点个数*/
    while (iterA != null || iterB != null) {
      if (iterA != null) {
        countA++;
        iterA = iterA.next;
      }
      if (iterB != null) {
        countB++;
        iterB = iterB.next;
      }
    }
    /*计算2个链表的差额*/
    int margin;
    ListNode ia = headA;
    ListNode ib = headB;
    if (countA > countB) {
      margin = countA - countB;
      while (margin > 0) {
        ia = ia.next;
        margin--;
      }
    } else {
      margin = countB - countA;
      while (margin > 0) {
        ib = ib.next;
        margin--;
      }
    }
    /*补平差额后一起向后移动，当2个链表的节点相等时返回相遇节点*/
    while (ia != null && ib != null) {
      if (ia == ib) {
        return ia;
      }
      ia = ia.next;
      ib = ib.next;
    }
    return null;
  }
```
