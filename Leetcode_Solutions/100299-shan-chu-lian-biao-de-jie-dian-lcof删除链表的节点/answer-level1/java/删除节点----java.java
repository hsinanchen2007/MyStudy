```
class Solution {
    public ListNode deleteNode(ListNode head, int val) {
        if(head == null){
            return null;
        }
        //创建一个虚拟头指针
        ListNode oldcur = new ListNode(-1);
        oldcur.next = head;
        ListNode prev = oldcur;
        //prev != null该条件是用于删除的元素是链表尾元素的情况是退出循环的
        while(prev != null && prev.next != null){
            if(prev.next.val == val){
                prev.next = prev.next.next;
            }
            prev = prev.next;
        }
        return oldcur.next;
    }
}
```
