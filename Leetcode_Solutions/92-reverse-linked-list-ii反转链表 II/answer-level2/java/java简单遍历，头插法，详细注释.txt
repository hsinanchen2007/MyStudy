```
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode res = new ListNode(0);
        res.next = head;     //在链表之前在放置一个节点，针对将整个链表翻转。
        ListNode pre,index=res;
        int i=1;
        while(++i<=m)index=index.next;//找到第m个位置的前驱
        pre = index;
        index=index.next;

        while(m<n&&index!=null){//头插法
            ListNode t = pre.next;
            pre.next = index.next;
            index.next = index.next.next;
            pre.next.next = t;
            m++;
        }
        
        return res.next;
    }
}
```
