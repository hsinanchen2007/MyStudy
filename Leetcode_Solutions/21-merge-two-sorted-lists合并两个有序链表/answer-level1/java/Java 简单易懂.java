
执行用时：0 ms
内存消耗：39 MB
``` java
class Solution {
  /**  
   * 比较2个节点，放入新链表中
   * @param l1
    * @param l2
    * @return
    */
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode curr1 = l1;
        ListNode curr2 = l2;
        ListNode temp = dummy;
        while (curr1 != null && curr2 != null) {
            if (curr1.val > curr2.val) {
                temp.next = curr2;
                curr2 = curr2.next;
            } else {
                temp.next = curr1;
                curr1 = curr1.next;
            }
            temp = temp.next;
        }
        if (curr1 != null) {
            temp.next = curr1;
        }
        if (curr2 != null) {
            temp.next = curr2;
        }
        return dummy.next;
    }
}
```

