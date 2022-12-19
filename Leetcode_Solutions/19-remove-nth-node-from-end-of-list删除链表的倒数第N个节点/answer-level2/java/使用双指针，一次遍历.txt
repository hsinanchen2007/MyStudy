1.  使用两个指针left, right分别指向头节点，先让right结点先走n步，若出现right结点为空，则说明n大于等于链表长度，可返回头节点的下一个结点
2. 在分别移动left,right指针，知道right到链表尾部
```
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head==null){
            return head;
        }
        ListNode left = head;
        ListNode right = head;
        
        while(n-- > 0){
            right = right.next;
            if(right ==null){
                return left.next;
            }
        }
       
        while(right.next!=null){
            left =left.next;
            right = right.next;
        }
        left.next = left.next.next;
        return head;
    }
}
```


