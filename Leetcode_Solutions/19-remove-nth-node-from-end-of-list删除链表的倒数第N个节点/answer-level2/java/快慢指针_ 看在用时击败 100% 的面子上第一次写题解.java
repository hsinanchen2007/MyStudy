看在这个用时击败100%才写的题解，哈哈
![Snipaste_2020-02-28_21-02-31.png](https://pic.leetcode-cn.com/21ede3925e6cf03a65e5a229bcf791ab55b8598272c6b03da964f1eb27332876-Snipaste_2020-02-28_21-02-31.png)

第一次写题解，有什么好的建议希望大家提出来一起讨论。
思路：主要的思想是利用**快慢指针**。同时还需要设定两个整型下标sIndex和fIndex分别记录快慢指针的位置。然后还需要一个preSlow位置来记录慢指针的前一个节点。（因为后续过程可能会出现要删除的节点就是slow节点情况，那么就会丢失前一个节点的信息）
1. 首先从头节点开始，快指针一次遍历两个节点，慢指针一次遍历一个节点。
        注意在遍历的过程中，快指针可能会出现在遍历一次之后就为空的情况，需要进行处理。
2. 第一步会进行 len/2 次遍历，快指针来到链表尾部，慢指针在中间节点位置。然后结合 n以及fIndex的信息可以求出要删除节点的下标 `delIndex = fIndex - n`
3. 之后根据 delIndex 的位置决定从sIndex的左边还是右边进行遍历找到要删除的节点进行删除即可。
代码如下：
**时间复杂度O(N), 空间复杂度O(1).**
```java
public static ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null)
            return null;
        // 分别用于记录慢指针、快指针的下标
        int sIndex = 0;
        int fIndex = 0;
        // 定义快慢指针
        ListNode slow = head;
        ListNode fast = head;
        // 用于记录慢指针的前一个结点信息
        ListNode slowPre = null;
        while (fast != null){
            slow = slow.next;
            slowPre = slow;
            sIndex++;
            // 因为快指针可能在走一步之后就到达空，所以需要提前判断，两步分开走
            fast = fast.next;
            fIndex++;
            if (fast == null)
                break;
            fast = fast.next;
            fIndex++;
        }

        // 计算要删除的节点下标
        int delIndex = fIndex - n;
        if (delIndex == 0)
            return head.next;
        // 如果在慢指针右边就从慢指针处开始遍历，如果正好在慢指针位置就可以结合slowPre进行删除
        else if (delIndex >= sIndex){
            while (sIndex != delIndex){
                sIndex++;
                slowPre = slow;
                slow = slow.next;
            }
            slowPre.next = slow.next;
            return head;
        }else{
            // 在慢指针左边的情况
            int i = 1;
            slowPre = head;
            ListNode sta = head.next;
            while (i < delIndex){
                i++;
                slowPre = sta;
                sta = sta.next;
            }
            slowPre.next = sta.next;
            return head;
        }
    }
```
