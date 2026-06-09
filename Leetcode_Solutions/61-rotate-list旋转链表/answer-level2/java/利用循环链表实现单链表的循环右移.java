### 解题思路
利用***单向循环链表***实现单向链表右移的功能。
思路是：先将单向链表成环，找出右移后的新的头结点，然后将循环链表断裂成单链表，返回新头结点即可。

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
        //判断，若是特殊情况，则直接返回
        if(head == null) return null;
        if(k == 0 || head.next == null) {
            return head;
        }

        ListNode tempNode = head;
        //尾结点，用于单链表成环
        ListNode tailNode = null;
        //单链表的长度
        int lens = 0;
        while(tempNode != null) {
            lens++;
            if(tempNode.next == null)
                tailNode = tempNode;
            tempNode = tempNode.next;
        }
        
        if(lens == k) return head;
        //头结点
        tempNode = head;
        //成环
        tailNode.next = head;
        if(lens < k) k = k%lens;
        for(int i = 0; i < lens-k-1; i++) {
            tempNode = tempNode.next;
        }
        //找到新的头结点
        head = tempNode.next;
        //断裂环，还原成单向列表
        tempNode.next = null;
        //返回该结点作为循环移动后的头结点
        return head;
    }

}
```