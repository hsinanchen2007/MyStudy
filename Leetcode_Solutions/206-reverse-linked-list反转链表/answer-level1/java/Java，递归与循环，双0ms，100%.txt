## 循环
### 解题思路
先把前面的指针都翻转好，处理当前的指针时面临的情况是：
```
...<-prv cur->nxt->...
```

现在需要把cur指向prv，所以需要保存cur的nxt，方便接下来找到它，然后改变cur的指针指向到prv。情况变成：
```
...<-prv<-cur nxt->...
```


接下来移动prv、cur指针，向右走，使得每个next指针需要反向的点都作为cur来操作一次。
考虑Corner cases：
1. 头结点：`head->headNxt->...，`最终目标是head的next为空，headNxt的next指向head。所以一开始使得cur为headNxt，prv为head，使得headNxt回指head。并且注意把head的next置位空。
2. 尾节点：`...->prv->cur`.变为`...<-prev<-cur.`最后的尾节点的next指针会被翻转，所以cur会经历过尾节点。当尾节点经历完之后，cur会走到null，prv走到尾节点，所以这个prv作为新的头结点返回。

### 代码
```
    //循环： ...<-prv  cur->nxt变成 ...<-prv<-cur  nct移动指针
 public ListNode reverseList(ListNode head) {
        if(head==null||head.next==null){
            return head;
        }
        
        ListNode cur=head.next;//第一个需要翻转的边是head.next的指针
        head.next=null;
        ListNode prv=head;
        while(cur!=null){
            ListNode nxt=cur.next;
            cur.next=prv;

            prv=cur;
            cur=nxt;
        }
        return prv;
    }
```

## 递归
### 解题思路
递归的思想是利用递归函数，把head.next后面的都翻转好了，然后再处理当前节点。当head.next都翻好了是这样的情况：
```
head nxt<-....<-last
```

这时候需要把nxt的next指针指向head即可。然后返回last作为新的链表的头结点。
注意需要把head.next置位null。否则，会出现`head<->nxt<-...`。next互相指的情况，从而出现死循环。



### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {

//递归：后面的都翻转好了 head  nxt<-..<-last 变成 head
    public ListNode reverseList(ListNode head) {
        if(head==null||head.next==null){
            return head;
        }
        ListNode nxt=head.next;
        head.next=null;//如果没有这一句，第一个节点的next没有被改，会互相指
        ListNode newHead=reverseList(nxt);
        nxt.next=head;//这里要求递归不会返回null，所以在入口第一句要加上head.next==null
        return newHead;
    }
}
```