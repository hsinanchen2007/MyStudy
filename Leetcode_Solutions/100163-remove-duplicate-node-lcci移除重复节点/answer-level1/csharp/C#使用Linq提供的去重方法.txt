不修改原有链表，需要重建新的链表；
相信标准库的去重方法比自己使用 HashSet 要快。
```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    IEnumerable<int> ForEachListNode(ListNode head) {
      var p = head;
      while (p != null) {
        yield return p.val;
        p = p.next;
      }
    }
    public ListNode RemoveDuplicateNodes(ListNode head) {
      var tempHead = new ListNode(0);
      var p = tempHead;
      foreach(var x in ForEachListNode(head).Distinct()) {
        p.next = new ListNode(x);
        p = p.next;
      }
      return tempHead.next;
    }
}
```
