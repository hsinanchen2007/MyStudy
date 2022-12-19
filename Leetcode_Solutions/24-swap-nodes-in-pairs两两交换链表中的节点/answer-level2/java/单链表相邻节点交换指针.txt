### 解题思路
此处撰写解题思路
首先明白链表的结构，是对象中存储下一个节点对象的地址
针对本题来说，不能直接修改头节点指向第二节点的下一个节点，因为第三和第四节点也是可以进行交换的，
正确的思路是第一个节点指向第二节点后的字链表
    第二节点指向第一节点
直到子链表的节点个数为1或者是null。
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
    public ListNode swapPairs(ListNode head) {
       //链表数据结构对象中存储下一个对象的地址
       //针对本题来说是交换两两相邻的节点的指针所以不能直接将头指针指向原链表的第三个节点，因为原链表的第三个指针也是会改变的
       //可以将头结点（前置节点指向后续链表），这种递归的思想
       if(head == null || head.next == null){
           return head;
       }
       ListNode firstNode = head;
       ListNode secondNode = head.next;
       firstNode.next = swapPairs(secondNode.next);
       secondNode.next = firstNode;
       return secondNode;
    }
}
```