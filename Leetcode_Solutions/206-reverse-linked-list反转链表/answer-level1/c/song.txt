### 解题思路
该题有两种解题思路，分别是迭代法和递归法
相比递归法迭代法更加容易理解，我还是个初学者，仅仅为了记录自己的学习过程
class Solution {
   public ListNode reverseList(ListNode head) {
    if (head == null || head.next == null) return head;
    ListNode p = reverseList(head.next);
    head.next.next = head;
    head.next = null;
    return p;
}
}