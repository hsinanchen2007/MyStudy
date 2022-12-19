使用递归的时候就认为函数功能已经实现了，reverseList(head.next) 使得 head.next 已经逆序了,我们只要把头结点放到逆序链表的最后面就行了。
```
class Solution {
    public ListNode reverseList(ListNode head) {
        // if(head == null) return null;
        // if(head.next == null) return head;
        // ListNode node = reverseList(head.next);
        // if(node != null){
        //     ListNode last = node;
        // // 慢的原因是因为每次反转之后都需要去找最后一个节点的位置
        //     while(last.next!=null){
        //         last = last.next;
        //     }
        //     head.next = null;
        //     last.next = head;
        // }
        // return node;

        // 其实并不需要依次找，因为 head.next 在反转之后 head.next 就到了最后的位置，记录一下就行
        // 特别注意链表边界处理
        if(head == null) return null;
        if(head.next == null) return head;
        ListNode last = head.next;
        ListNode reverse = reverseList(head.next);
        head.next = null;
        last.next = head;
        return reverse;
    }

}
```
