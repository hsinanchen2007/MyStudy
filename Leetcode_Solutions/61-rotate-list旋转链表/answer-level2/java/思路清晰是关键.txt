### 解题思路
做链表题目思路清晰是关键，很容易迷糊，先在纸上画一画，然后写代码的时候务必加上注释，这样自己不会
写一会就迷糊了。
几个关键步骤
1.获取链表长度取模得到真正的k，同时记录一下最后一个链表lastNode;
2.找到倒数第K个前一个节点和倒数第K个节点；
3.倒数第K个前一个节点指向null，断掉原来的链表；
4.尾结点指向头节点。

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
   public ListNode rotateRight(ListNode head, int k) {
       if (head == null) {
            return head;
        }
        ListNode cur = head;
        int length = 1;
        while (cur.next != null) {
            cur = cur.next;
            length++;
        }

        ListNode lastNode = cur;
        //取模得到真正的k。
        k = k % length;
        if (k == 0) {
            return head;
        }

        ListNode kNode = head;

        while (k > 0) {
            kNode = kNode.next;
            k--;
        }


        ListNode tmp = head;
        while (kNode.next != null) {
            tmp = tmp.next;
            kNode = kNode.next;
        }


        //倒数第K个节点是最后的头节点。
        ListNode result = tmp.next;
        //这个tmp得到的是倒数K个节点的前一个，这个后面要指向null，断掉原来的链表。
        tmp.next = null;
        //尾结点指向头结点。
        lastNode.next = head;
        return result;
    }
}
```