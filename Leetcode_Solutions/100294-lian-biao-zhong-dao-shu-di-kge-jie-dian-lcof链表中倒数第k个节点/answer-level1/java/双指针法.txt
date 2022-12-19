```
class Solution {
    public ListNode getKthFromEnd(ListNode head, int k) {
        ListNode fast = head;
        ListNode slow = head;

        //fast指针先往前走k-1步
        int tempK = k-1;
        while(tempK > 0 && fast!=null){
            fast = fast.next;
            tempK--;
        }
        //注意：边界条件，k大于链表长度
        if (fast==null){
            return null;
        }
        //快慢指针一起往前走，快指针到达最后一个结点时，慢指针所指的就是倒数第k个结点
        while(fast.next!=null){
            fast = fast.next;
            slow = slow.next;
        }
        return slow;
    }
}
```
