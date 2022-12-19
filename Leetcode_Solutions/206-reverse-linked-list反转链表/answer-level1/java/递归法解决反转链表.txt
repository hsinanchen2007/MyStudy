### 解题思路
假设链表为1->2->3->4->5->null。则递归的做法是：先循环找到最后面指向的数5，然后从5开始处理依次翻转整个链表。其中有两个指针，一个是head指针。指向当前函数内的头结点。另一个是newhead指针，指向递归递进过程中的最后一个节点。过程如下所示：
![image.png](https://pic.leetcode-cn.com/857be47eeb9f29c09736ecc75e68bbd0e185f98ef3689fe57396add1963504b6-image.png)


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
        if(head==null||head.next==null){
            return head;
        }
        else{
            ListNode newHead = reverseList(head.next);
            head.next.next = head;
            head.next = null;
            return newHead;
        }
    }
}
```