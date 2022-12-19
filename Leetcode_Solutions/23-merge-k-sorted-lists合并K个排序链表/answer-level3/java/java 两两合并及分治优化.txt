**思路一：逐一两两合并** 将[NO.21合并两个有序链表](https://blog.csdn.net/qq_42758551/article/details/103733958)中的方法进行k-1次即可。

![3C5BHU.png](https://pic.leetcode-cn.com/d77788e3b7328f9a24d23e978b14a99ea50c3c603e061d05ffd17c68f33b9aeb.png)

```java
public ListNode mergeKLists(ListNode[] lists) {
    if (lists==null||lists.length==0)return null;
    if (lists.length<2)return lists[0];
    ListNode dummy=new ListNode(-1);
    dummy.next=lists[0];
    for (int i=1;i<lists.length;i++){
        ListNode head=dummy,p=dummy.next,q=lists[i];
        while (q!=null&&p!=null){
            if (q.val< p.val){
                head.next=q;
                q=q.next;
            }else {
                head.next=p;
                p=p.next;
            }
            head=head.next;
        }
        if (q!=null)head.next=q;
        if (p!=null)head.next=p;
    }
    return dummy.next;
}
```

时间复杂度：O(Nk)   N是节点总数，k是链表数

**思路二：分治法优化两两合并** 每次对折合并，0号链表和length-1号链表合并保存到0、1号链表和length-2号链表合并保存到1。。。第一轮合并后，将0~k/2再次对折两两合并。。。以此类推，最后0号链表就是最终结果。

![3C5y4J.png](https://pic.leetcode-cn.com/b07a82fff1dde58ac485f6372d90e620d7819891601c2a07a52c5a07e037629c-3C5y4J.png)


```java
public ListNode mergeKLists(ListNode[] lists) {
    int len = lists.length;
    if (lists==null|| len ==0)return null;
    while (len>1){
        for (int i=0;i<len/2;i++){
            //中心对称，两两合并
            lists[i]=mergeTwoList(lists[i],lists[len-1-i]);
        }
        len=(len+1)/2;
    }
    return lists[0];
}
//合并两个链表
public ListNode mergeTwoList(ListNode l1,ListNode l2){
    ListNode dummy=new ListNode(-1);
    ListNode head=dummy,p=l1,q=l2;
    while (p!=null&&q!=null){
        if (p.val<q.val){
            head.next=p;
            p=p.next;
        }else {
            head.next=q;
            q=q.next;
        }
        head=head.next;
    }
    if (q!=null)head.next=q;
    if (p!=null)head.next=p;
    return dummy.next;
}
```

时间复杂度：O(Nlogk)	N是节点总数，每次对折合并所有节点都参与了，一共对折合并了logk次。

本人菜鸟，有错误请告知，感激不尽！

更多题解和学习记录博客:[博客](https://blog.csdn.net/qq_42758551)、[github](https://jerrymouse1998.github.io/)