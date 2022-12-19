想要使用自有方法进行递归，主要需要处理的就是加一部分，当有加一时，直接把加一加到l1上，在l1为空时新建一个为1的l1

```
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
       ListNode dummy = new ListNode(0);
        if (l1 != null || l2 != null) {
            dummy.val = ((l1 != null) ? l1.val : 0) + ((l2 != null) ? l2.val : 0);
            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
            if(dummy.val >= 10){
                if (l1 != null) l1.val += 1;
                else l1 = new ListNode(1);
                dummy.val %= 10;
            }
            dummy.next = addTwoNumbers(l1, l2);
        }else{
            return null;
        }
        return dummy;
    }
}
```
