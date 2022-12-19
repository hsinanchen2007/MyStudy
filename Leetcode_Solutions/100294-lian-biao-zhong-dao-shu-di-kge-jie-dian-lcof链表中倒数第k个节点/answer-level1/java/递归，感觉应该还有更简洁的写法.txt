```java
class Solution {
    ListNode res = null;
    int count = 0;
    int kth ;
    public ListNode getKthFromEnd(ListNode head, int k) {
        kth = k;
        getKth(head);
        return res;
    }

    public void getKth(ListNode head){
        if(head==null)return;
        getKth(head.next);
        count++;
        if(count==kth)res=head;
    }
}
```
