这个思路非常直观，就是把奇数位置的节点和偶数位置的节点各组成一个子链表，然后给它们连起来就可以了。
- 首先需要设置两个指针分别在遍历链表时来进行两个子链表的创建。
- 此外，还需要用两个指针来保存子链表的头节点，方便最后返回最终的头节点和用于子链表的连接。
- 关于链表遍历时如何的问题，我选择定义了一个boolean遍历，每次都将它取反，就能实现奇偶交替处理。
```
class Solution {
    public ListNode oddEvenList(ListNode head) {
        ListNode oddHead = new ListNode(-1);
        ListNode evenHead = new ListNode(-1);
        ListNode odd = oddHead,even = evenHead,cur = head;
        boolean isOdd = true;
        while(cur != null){
            if(isOdd){
                odd.next = cur;
                odd = cur;
            }else{
                even.next = cur;
                even = cur;
            }
            isOdd = !isOdd;
            cur = cur.next;
        }
        odd.next = evenHead.next;
        even.next = null;
        return oddHead.next;
    }
}
```
