![1](https://pic.leetcode-cn.com/76c97deabe56f2516665f09244dbbce36d8211ec754dcf118e063e1b37287ae5-QQ%E5%9B%BE%E7%89%8720200326212346.png)
```
 public static ListNode removeNthFromEnd(ListNode head, int n) {
//添加一个头结点
        ListNode listNode = new ListNode(-1);
       listNode.next=head;
        if (listNode.next != null) {
            int i = removeNthFromEndo(listNode, n);
        }else {
//解决只有一个元素的情况
            if (n==1) return null;
        }
        return listNode.next;
    }

    private static int removeNthFromEndo(ListNode head, int n) {
        if (head.next != null) {
           n= removeNthFromEndo(head.next, n);
            if (n==0){
                ListNode p=head;
                p.next=p.next.next;
            }
        }
        n--;
        return n;
    }
```
