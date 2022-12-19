无脑往L1合并就对了
```java
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode mhead = new ListNode(Integer.MIN_VALUE);
        mhead.next = l1;
        ListNode p1 = mhead;
        ListNode p2 = l2;
        while(null != p1 && null != p2){
            if(p1.next == null || p2.val <= p1.next.val){
                ListNode temp = p2;
                p2 = p2.next;
                temp.next = p1.next;
                p1.next = temp;
            } else {
                p1 = p1.next;
            }
        }
        return mhead.next;
    }
}
```
