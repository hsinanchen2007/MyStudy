此题分为3步完成：
1. 将用于翻转链表的指针移动到合适开始的位置；
2. 利用翻转链表的指针的更新操作，实现需要的翻转位置的成功翻转；
3. 将剩余部分与已经成功翻转的部分链接起来。

根据上面的描述，最复杂的部分是第三步，为了完成第三步，我们需要提前多设几个指针，保存上下文，以方便链接操作。
而且，此处还有特殊情况需要考虑。

>翻转涉及的指针操作  
m&emsp;&emsp;m+1&emsp;&emsp;m+2 &emsp;...&emsp;n  
pre&emsp;&emsp;cur&emsp;&emsp;next  
1&emsp;&rarr;&emsp;2 &emsp;&rarr; &emsp;3&emsp;&rarr;  
cur.next = pre;
pre = cur;
cur = next;  
1&emsp;&larr;&emsp;2  
继续上面的过程，按需迭代若干次.

``` java
public ListNode reverseBetween(ListNode head, int m, int n) {
    	ListNode preP = null;
        ListNode pre = null;
        ListNode cur = head;
        ListNode next = null;
        
        for (int i = 0; i < m; i++) {
        	next = cur.next;
        	preP = pre;
        	pre = cur;
        	cur = next;         	
        }
        
        ListNode tail = pre;
        for (int i = 0; i < n - m; i++) {
        	next = cur.next;
        	cur.next = pre;
        	pre = cur;
        	cur = next;
        }
        

        if (tail != null) {
        	tail.next = cur; 
        }
        
        if (preP != null) {
        	preP.next = pre;
        	return head;
        }
        
        return pre;
    }
```
preP 指针，用来记录 m - 1 的节点位置，方便之后串接到 n 节点的位置；
pre、cur 以及 next 指针，配合cur以及next指针完成指针 m 和 n 节点之间所有节点位置的翻转；
tail 指针记录 m 节点位置，作为翻转的部分的末尾，利用其连接链表的最后一部分；

返回值：返回表头节点，在这里有一个陷阱，如果head也参与了翻转，则不能简单的返回head，那么我们怎么判断head有没有参与翻转呢？这里面preP指针的作用就体现了，如果preP指针是null，说明head参与翻转了，那么显然 最后的 pre 指针指向的节点就是新的头结点了。
