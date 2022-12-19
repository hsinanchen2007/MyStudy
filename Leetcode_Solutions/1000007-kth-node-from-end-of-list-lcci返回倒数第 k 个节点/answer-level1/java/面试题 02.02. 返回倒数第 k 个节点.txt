```
class Solution {
    /*
        先计算链表的长度n，然后从头找第n-k个节点，即为倒数第k个节点。（这就双百了？离谱！）
    */
    public int kthToLast(ListNode head, int k) {
        int n = 0;
        ListNode node = head;
        while(node!=null){
            n++;
            node = node.next;
        }  
        node = head;
        for(int i=0; i<n-k; i++){
            node = node.next;
        }
        return node.val;
    }
}
```
```
class Solution {
    /*
        双指针技巧，一样双百。
        1. p，q都位于头节点，首先让q向后移动k次，此时p，q相距k。
        2. 同时将p，q后移，直到q到达链表尾，此时p刚好为倒数第k个节点。
    */
    public int kthToLast(ListNode head, int k) {
        ListNode p,q;
        p=q=head;
        for(int i=0; i<k; i++){
            q = q.next;
        }
        while(q != null){
            p = p.next;
            q = q.next;
        }
        return p.val;
    }
}
```

