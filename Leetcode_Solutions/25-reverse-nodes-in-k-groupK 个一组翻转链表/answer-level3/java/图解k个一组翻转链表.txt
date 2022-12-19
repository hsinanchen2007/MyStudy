###### 题目25，24：
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

示例 :

给定这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

说明 :

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

###### 题解：
这个题在leetcode属于困难型，对于这个题的解法可以这样想：
首先，对一个链表的翻转我们肯定很熟悉，那么k个一组不就是翻转k个链表嘛，不过是翻转之前需要将未翻转的标记一下next，翻转了过后再将第一个链表的尾节点start.next  = next，然后在循环进行下一个链表的翻转，直接将翻转封装成一个方法reverse（ListNode start）。在翻转的时候为了让头节点也有前驱，我们自己定义一个headHead，如图所示：
一次翻转结束，更新pre end，start，end进行下一次翻转，如果end为到达指定的长度就结束了，说明节点数不够了嘛，然后就不用翻转了。整个操作空间复杂度O（1），常数额外空间，时间复杂度O（n*k），在题解中还看到一种优化说不用判断最后一个链表的长度，直接翻转就完了，如果最后发现长度不够再翻转回来，各位可以试试。
![在这里插入图片描述](https://pic.leetcode-cn.com/1b722b9ab4815238146c1660d4662ef682b0b151bffa69afce4ba09595346ede.png)

给出我的结果以及代码：
![在这里插入图片描述](https://pic.leetcode-cn.com/0468631b64911e0e4f71a01e01088f41262c0572a030cc1d74e2e15d6b1d556e.png)

```powershell
public ListNode reverseKGroup(ListNode head, int k) {
	//如果为空，或者只有一个节点，直接返回嘛
        if (head == null || head.next == null){
                return head;
        }

//给头节点一个前驱，不用单独为头节点考虑了
        ListNode headHead = new ListNode(-1);
        headHead.next = head;
        ListNode pre = headHead;
        ListNode end = headHead;
        while (end.next != null){
            //end移动到末尾
            for (int i = 0; i <k&&end!=null ; i++) {
                end = end.next;
            }
            if (end == null){
                break;
            }
            ListNode start = pre.next;
            ListNode next = end.next;
            end.next = null;
            //翻转链表，将头连接到上一个链表的末尾
            pre.next = reverse(start);
            //末尾要连接到下一个连接的next，
            start.next = next;
            pre = start;
            end = start;
        }
        return headHead.next;
    }


    //翻转链表
    private ListNode reverse(ListNode start) {
        if (start == null || start.next == null){
            return start;
        }
        ListNode p = start;
        ListNode q = start.next;
        while (q != null){
            ListNode t = q.next;
            q.next = p;
            p = q;
            q = t;
        }
        start.next = null;
        return p;
    }```
