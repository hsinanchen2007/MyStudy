> 思路：双指针，以外层的值作为标准进行对比，如果相同，则在退出循环的时候同时删除该节点。时间复杂度 O(n)

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
  public ListNode deleteDuplicates(ListNode head) {
    if (head == null || head.next == null) return head;
    ListNode p1 = new ListNode(0),
            p2 = p1;
    p1.next = head;
    int curr = head.val - 1;
    while(p1.next != null) {
      ListNode tmp = p1.next;
      boolean flag = false;
      while(tmp.next != null) {
        if (tmp.val != tmp.next.val) break;
        else {
          flag = true;
          tmp.next = tmp.next.next;
        }
      }
      if (flag) p1.next = tmp.next;
      else p1 = tmp;
    }
    return p2.next;
  }
}
```