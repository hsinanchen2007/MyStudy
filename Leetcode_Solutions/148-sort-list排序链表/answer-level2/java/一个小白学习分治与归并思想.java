### 解题思路
1.我是一个小白开发2年经验想要提升自己开始看算法相关书籍，刷题感觉异常费劲。我报了一个在线培训班看了几节算法相关课程现在做题有思路了。
2.找个题是分治与归并思想的体现。
3.8 3 2 3 4 5 6 1
4.先进行拆分成两块 8 3 2 3 和 4 5 6 1
5.在进行拆分8 3、2 3、4 5、6 1
6.在进行拆分8、3、2、3、4、5、6、1
7.在进行合并合并过程中需要进行排序，两个链表合并成一个链表。
8.3 8、2 3、4 5、1 6
9.2 3 3 8、1 4 5 6
10.1 2 3 3 4 5 6 8
11.上述操作中可以抽取出三个方法
12.方法一拆分方法sortList并且是递归调用，递归终止条件为链表变成一个节点。
13.方法二拆分方法将一个链表从中间分为两个getMid。
14.合并排序方法，将两个链表合并成一个。
15.通过这三个方法就将3-10步模拟出来了。

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
       public  ListNode merge(ListNode head1, ListNode head2){
        if (head1 == null || head2 == null) {
            return head2 != null ? head1 : head2;
        }
        ListNode head = head1.val < head2.val ? head1 : head2;
        ListNode cur1 = head1 == head ? head1 : head2;
        ListNode cur2 = head1 == head ? head2 : head1;
        // 定义当前节点的上节点
        ListNode pre = null;
        ListNode next = null;
        while (cur1 != null && cur2 != null) {
            if (cur1.val <= cur2.val) {
                pre = cur1;
                cur1 = cur1.next;
            } else {
                // 交换 cur1 和 cur2
                  next = cur2.next;
                cur2.next = cur1;
                pre.next = cur2;
                cur1 = cur2;
                cur2 = next;
            }
            pre.next = cur1 == null ? cur2 : cur1;
        }
        return head;
    }

    public  ListNode getMid(ListNode node){
        if (node == null) {
            return node;
        }
        ListNode firstNode = node;
        ListNode sendNode = node;
        while (sendNode.next != null && sendNode.next.next != null) {
            firstNode = firstNode.next;
            sendNode = sendNode.next.next;
        }
        return firstNode;
    }


    public  ListNode sortList(ListNode node){
        
        if (node == null || node.next == null) {
            return node;
        }
        ListNode mid = this.getMid(node);
        ListNode right = mid.next;
        mid.next = null;
        ListNode merge = this.merge(this.sortList(node), this.sortList(right));
        return merge;
    }
}
```