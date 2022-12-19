一遍写完，调试了几下，基本一遍过，用时0ms，值得记录
思路：
1：首先找到要返回的头结点，头结点是链表第k个节点，因为前k个节点反转之后，第k个节点变成了头结点。
2：写一个反转链表的工具函数
3：用一个指针preK指向前面已经反转好了的部分链表的尾节点，初始时，指向空
4：循环，每次找到当前的前k个节点，Ni,Ni+1,...,Ni+k-1, nhead=Ni,ntail=Ni+k-1，找到后
```
next = ntail.next;
ntail = null;
```
将后面剩下的节点断开，同是用一个next指针指向后面的节点。
5：对这k个节点进行链表反转，反转后，nhead变成了尾部，ntail变成了头部，
此时，如果preK为空，说明这是第一个 k个几点，直接把`preK=nhead`;如果preK不为空，说明这已经不是第一个k个节点了，需要`preK.next=ntail; preK=nhead`,意思就是，把前面已经反转好了的链表尾部和新反转好的这k个节点的头部连接上，同是preK指向新的已经反转好的尾部。
6:继续循环，直到最后剩下少于k个节点，那么此时可以直接跳出循环，返回前面找好的头结点了。
完毕

```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null || k == 1) return head;
        ListNode newHead = null;
        int i = 1; 
        ListNode node = head;
        while(i++ < k) {
            node = node.next;
        }
        newHead = node;
        ListNode nhead = head;
        ListNode ntail = null;
        ListNode next = null;
        ListNode preK = null;
        boolean flag = false;
        while(nhead != null) {
            i = 1;
            node = nhead;
            while(node != null && i++ < k) {
                node = node.next;
            }
            if(node == null) break;
            ntail = node;
            next = ntail.next;
            ntail.next = null;
            reverseList(nhead);
            if(preK == null) {
                preK = nhead;
            } else {
                preK.next = ntail;
                preK = nhead;
            }
            nhead.next = next;
            nhead = next;
        }
        return newHead;
    }

    public ListNode reverseList(ListNode head) {
        if(head == null) return head;
        ListNode cur = head;
        ListNode pre = null;
        while(cur != null) {
            ListNode next = cur.next;
            if(next == null) {
                break;
            } 
            cur.next = pre;
            
            pre = cur;
            cur = next;
        }
        cur.next = pre;
        return cur;
    }
} 
```