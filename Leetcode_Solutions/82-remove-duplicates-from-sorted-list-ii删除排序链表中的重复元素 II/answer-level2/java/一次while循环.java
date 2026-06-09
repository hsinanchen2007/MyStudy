依次考虑相邻的3个元素pre--now--next，当(now.val != pre.val) && (now.val != next.val)的时候，就说明now这个元素是有效的。注意处理pre和next为空的临界条件。
```
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null)
            return null;
        ListNode h = null;
        ListNode t = null;
        ListNode pre = null;
        while(head != null){
            if(judge(pre,head)==true && judge(head,head.next)==true)
                if(h == null){
                    h = new ListNode(head.val);
                    t = h;
                }else{
                    t.next = new ListNode(head.val);
                    t = t.next;
                }
            
            pre = head;
            head = head.next;
        }
        return h;
    }
    public boolean judge(ListNode n1,ListNode n2){
        if(n1==null || n2==null ||(n1.val != n2.val))
            return true;
        return false;
    }
}

```