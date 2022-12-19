
![20191022150420673.png](https://pic.leetcode-cn.com/642ac73762d0688969dc343426ed26cf29576fb1327cd609763870b6177c99cf-20191022150420673.png)

```
// 206. Reverse Linked List
// https://leetcode-cn.com/problems/reverse-linked-list/description/
// 递归的方式反转链表
// 时间复杂度: O(n)
// 空间复杂度: O(n) （递归是占用空间的，占用空间的大小和递归深度成正比）
public class Solution {
    public ListNode reverseList(ListNode head) {
        // 递归终止条件
        if (head == null || head.next == null) {
            return head;
        }
        ListNode rhead = reverseList(head.next);
        // head->next此刻指向head后面的链表的尾节点
        // head->next->next = head把head节点放在了尾部
        head.next.next = head;
        head.next = null;
        return rhead;
    }
}

```
注意：rhead始终是最后一个节点
***
详细说明：[https://blog.csdn.net/qq_40794973/article/details/102631838]()