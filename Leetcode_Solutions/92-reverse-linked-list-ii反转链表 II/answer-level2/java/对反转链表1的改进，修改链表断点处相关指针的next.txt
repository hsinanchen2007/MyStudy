### 解题思路
这道题和反转链表有点相似，反转链表是将整个链表都反转，而这道题只是将范围m到n
的链表进行反转，**需要注意的是，将m到n的链表反转后，在两个端点处，设置好相应的
next即可，还有就是注意一些边界情况。**
下面代码在反转链表的基础上进行改进。
以1->2->3->4->5->NULL, m = 2, n = 4为例，
反转后，变为1->4->3->2->5->NULL。
在原来的链表上有两个端点，1 -> 2，和4 -> 5，反转后，节点1指向节点4（原来指向2），
节点2指向节点5，原来指向3。
我们需要先记录一下节点1，记为left，之后找到节点2，记为h，同时设置一个标志t指向2（因为在
链表部分反转后，t变为了反转后链表的尾节点，这个节点的next需要指向5，即原来链表上4的next，
反转后需要让t.next=5）
然后在节点2-5（此时可以看成一个
子链表）范围内进行反转，过程和反转链表的过程一致。
反转结束后pre指向了4，即要进行反转的子链表的头结点，要将节点1的下一个节点赋值为pre（left.next = pre）。
同时h指向了5，将t（节点2）的next设置为5，t.next=5;
需要注意的是，**当m=1时，原来链表的断点只有一个**，因此少了一个赋值next的步骤，不需要left.next = pre这一步。
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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (n == 1) {
            return head;
        }
        ListNode h = head;
        for (int i = 1; i < m - 1; i++) {
            h = h.next;
        }
        ListNode left = h;
        ListNode next = null;
        ListNode pre = null;  
        if (m != 1) {
            h = h.next;
        }
        ListNode t = h;
        for (int i = 1; i <= n - m + 1; i++) {
            next = h.next;
            h.next = pre;
            pre = h;
            h = next;
        }
        if (m == 1) {
            t.next = h;
            return pre;
        }
        left.next = pre;
        t.next = h;
        return head;
    }
}
```
![image.png](https://pic.leetcode-cn.com/fd85dcdaf15d4016ab72785561995dd46dc99636ae2653becc1d7c9670ea2b1d-image.png)
