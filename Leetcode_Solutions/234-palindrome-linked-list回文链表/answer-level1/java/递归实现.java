就是.....能跑emmmmmm
```
public boolean isPalindrome(ListNode head) {
    return head==null?true:(merg(head,head)==null?true:false);

}
public ListNode merg(ListNode start,ListNode end){
    if(end.next != null){
         ListNode merg = merg(start, end.next);
        if(merg == start){
            return start;
        }else{
            return merg.val == end.val?merg.next:start;
        }
    }else{
        return start.val == end.val?start.next:start;
    }
}
```