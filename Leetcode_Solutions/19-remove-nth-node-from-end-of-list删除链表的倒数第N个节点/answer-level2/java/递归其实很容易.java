```
class Solution {
    //递归做法
    int i;
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head == null){
            i=0;
            return null;
        }
        head.next = removeNthFromEnd(head.next,n);
        i++;
        if(i==n) return head.next;
        return head;
     }
}
```

第一次写题解...多多指教....