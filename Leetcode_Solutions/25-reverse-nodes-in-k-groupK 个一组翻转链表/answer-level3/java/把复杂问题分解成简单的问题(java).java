### 解题思路
我们把问题分解成几个子问题就容易了：
 - 从目标链表上切下前k个节点的子链表
 - 反转切下的链表
 - 把反转过的链表拼在一起
 - 循环这一过程直到链表末尾

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
  private ListNode reverseList(ListNode head) {
    ListNode n0 = null, n1 = head, n2 = head.next;
    while (n2 != null) {
      n1.next = n0;
      n0 = n1;
      n1 = n2;
      n2 = n2.next;
    }
    n1.next = n0;
    return n1;
  }

  private ListNode[] splitList(ListNode head, int k) {
    ListNode n = head, l = null;
    for (int i = 0; i < k; i++) {
      if (n == null) {
        return new ListNode[] { head, null };
      }
      l = n;
      n = n.next;
    }
    l.next = null;
    return new ListNode[] { head, n };
  }

  private ListNode concatList(ListNode l1, ListNode l2) {
    if (l1 == null) {
      return l2;
    }
    ListNode n = l1;
    while (n.next != null) {
      n = n.next;
    }
    n.next = l2;
    return l1;
  }

  private int length(ListNode head) {
    ListNode n = head;
    int c = 0;
    while (n != null) {
      n = n.next;
      c++;
    }
    return c;
  }

  public ListNode reverseKGroup(ListNode head, int k) {
    if (head == null || k < 1) {
      return head;
    }
    ListNode n = head;
    ListNode newHead = null;
    while (true) {
      ListNode[] r = splitList(n, k);
      if (r[1] == null) {
        newHead = concatList(newHead, (length(r[0]) < k) ? r[0] : reverseList(r[0]));
        break;
      }
      newHead = concatList(newHead, reverseList(r[0]));
      n = r[1];
    }
    return newHead;
  }
}
```