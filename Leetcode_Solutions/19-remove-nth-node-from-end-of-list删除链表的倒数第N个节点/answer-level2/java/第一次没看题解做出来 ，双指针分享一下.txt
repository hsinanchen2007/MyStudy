我开始考虑的情况太多了，没有仔细读题目。把N>链表长度的情况也考虑进去了。

创建两个指针从哑巴节点开始走，一个C指针先走N步，另外一个P指针在C指针走完的情况在，再开始，这样在C到达末尾的时候，自然P.next就是要删除的节点。

为什么从哑巴节点开始走，主要是个人习惯的问题。

```java
public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode d=new ListNode(-1);
        d.next=head;
        ListNode pre=d,c=d;
        for(int i=0;i<n;i++){
            if(c==null){
                return null;
            }//多余代码，防止N>链表长度
            c=c.next;
        }
        while (c.next!=null){
            pre= pre.next;
            c=c.next;
        }
        pre.next=pre.next.next;
        return d.next;
    }
```

**我不明白的是，为什么我的耗时1ms,我觉得没慢在哪里啊。**