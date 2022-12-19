递归
```
 public ListNode swapPairs(ListNode head) {
         if (head==null||head.next==null)
            return head;
        ListNode l = swapPairs(head.next.next); 
        ListNode out = head.next;       
        head.next.next = head;      
        head.next = l;
        return out;
}
```
迭代
```
 public ListNode swapPairs(ListNode head) {
     if (head==null||head.next==null)
            return head;
        ListNode cur = head;
        ListNode out = cur.next;
        ListNode pre = null;    //保存前一次操作后的末结点
        while (cur!=null&&cur.next!=null){
            ListNode next = cur.next.next;    
            if (pre!=null){     //如果不为空 说明有末结点可以连接
                pre.next = cur.next;
            }
            cur.next.next = cur;                 
            cur.next = next;
            pre = cur;
            cur = next;
        }
        return out;
}
```
结点的事情总是说起来很啰嗦。。有什么不懂的控制台打印一下吧！