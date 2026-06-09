### 解题思路
1.先判断空链的情况，如果为空直接返回head，这样最快，也避免空指针异常
if(head==null) return head;；
2.所谓的反转链表，就是把head的next的next替换成head，那么，我们需要一个空间去存放这个原来head.next.next节点，ListNode temp=null;
3.找到一个起始next节点，即head的next节点：ListNode next = head.next;
4.head.next已经拿到，那么head作为新链表的最末端，next应当变为null：
head.next=null;
5.接下来，while(next!=null)
temp =next.next;//先拿出原先的next.next,存起来；
next.next=head;//替换成head，完成第一个next的反转
然后重新定义head和next，即后移一位，继续重复操作：
head=next;
next=temp;

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
    public ListNode reverseList(ListNode head) {
        if(head==null) return head;
       ListNode next = head.next;
		ListNode temp=null;
		head.next=null;
		while(next!=null) {
			temp =next.next;
			next.next=head;
			head=next;
			next=temp;
		}
		return head;
    }
}
```