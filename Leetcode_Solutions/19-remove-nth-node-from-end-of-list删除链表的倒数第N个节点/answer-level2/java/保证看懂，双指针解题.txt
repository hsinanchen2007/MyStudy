![image.png](https://pic.leetcode-cn.com/fa558780e0c6249dcff6f9b99b936a4d534342b01870f2f681fd2f004f00b9d3-image.png)

这个题很好想，就相当于一组平行线向右移动，他们之间的距离不变。用俩指针初始化为head，然后一个指针跑n-1次，然后两个指针同时跑，当前面的指针为最后一个节点了，后一个就是要删除的节点了呗。
```
//两个指针一起跑就行了呗
    public ListNode removeNthFromEnd(ListNode head, int n) {
        //保证了n的有效
        ListNode p = head;
        ListNode q = head;
        ListNode t = head ;
        while (--n>0){
            p = p.next;
        }
        while(p.next != null && q.next != null){
            t = q;
            p = p.next;
            q = q.next;
        }
        if (q == head){
            head = head.next;
        }else{
            t.next = q.next;
        }
        return head;
    }
```
