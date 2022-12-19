两种方法差不多，一个生成链表，然后拼接，一个生成数组拼接，然后直接修改原链表的值，不用另外生成链表。

![image.png](https://pic.leetcode-cn.com/651a9abd36ec42ef65b320170383050458536695311082404ed3ee4bc98be181-image.png)

```
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        if head:
            l,r=ListNode(0),ListNode(0)
            ans=l
            tmp=r
            while head:
                if head.val<x:
                    l.next=ListNode(head.val)
                    l=l.next
                else:
                    r.next=ListNode(head.val)
                    r=r.next
                head=head.next
            l.next=tmp.next
            return ans.next
```

![image.png](https://pic.leetcode-cn.com/6a9969e8088c38e532343bbd26c7d21eba59fd87dd21e104fb7f60a775da342c-image.png)

```
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        if head:
            l,r=[],[]
            h=head
            while h:
                if h.val<x:
                    l+=[h.val]
                else:
                    r+=[h.val]
                h=h.next
            ans=head
            for i in l+r:
                head.val=i
                head=head.next
            return ans
```

两个方法都是三分钟就写完了，看官解才知道生成链表法和官解一模一样