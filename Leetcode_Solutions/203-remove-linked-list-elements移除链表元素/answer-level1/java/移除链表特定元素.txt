```
class Solution {
    public ListNode removeElements(ListNode head, int val) {
         ListNode L = new ListNode(-1);//增加头结点，用来删除第一个元素就相等
        L.next = head;
        ListNode p = head;
        ListNode pre = L;
        while (p != null){
            if (p.val == val){
                pre.next = p.next;
                p = pre.next;
            }else {
                p = p.next;
                pre = pre.next;
            }
        }
        return L.next;
    }
}
```
