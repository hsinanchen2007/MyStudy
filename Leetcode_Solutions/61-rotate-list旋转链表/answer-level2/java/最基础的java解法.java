```
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        ListNode p = head;
        ListNode oldhead = head;
        int len = 0;
        while(p!=null){ len++; p=p.next;} //求出链表长度
        
        if(head==null||k%len==0) return head; //剔除链表不变的情况
        
        int i = 1;
        p = head;

        //找到新head的前一个结点,即新链尾
        while(i != len - k%len){
            p=p.next;
            i++;
        }
        head = p.next;

        ListNode m = head;
        while(m.next!=null) m=m.next;  //遍历至末尾
        m.next = oldhead;  //末尾指向原head 

        p.next = null;  //链尾指向空
        
        return head;
    }
}
```
