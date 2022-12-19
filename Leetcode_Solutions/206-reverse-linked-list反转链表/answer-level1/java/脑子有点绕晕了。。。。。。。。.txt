### 解题思路
![QQ图片20200314161234.jpg](https://pic.leetcode-cn.com/064f4b8dcb7e7a75e801d7a0a28e334c5976024c2f3fc320db4b220ffe567cd5-QQ%E5%9B%BE%E7%89%8720200314161234.jpg)
此处撰写解题思路

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
        if(head == null || head.next == null){
            return head;
        }
        //创建个newHead
        ListNode newHead = null;
        while(head != null){
            //临时节点指向下一个节点
            ListNode tempNode = head.next;
            //head指向新headhead
            head.next = newHead;
            //新头节点指向旧头节点
            newHead = head;
            //原先的链表的头结点变为临时节点
            head = tempNode;
        }
        return newHead;

        /**
        //递归
        if(head == null || head.next == null){
            return head;
        }
        ListNode newHead = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return newHead;**/
    }
}
```