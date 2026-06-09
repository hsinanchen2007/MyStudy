### 解题思路
1. 先判断链表长度是否大于k，不大于直接返回
2. 若大于，则进行k-1次逆序，每次逆序一个节点。
3. 后返回逆序后的head，将其设置为前一次逆序的next（递归实现）
> 解题的关键在于链表翻转，可以先试着学习翻转单链表的实现。

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
    public ListNode reverseKGroup(ListNode head, int k) {
        int length = 0;
        ListNode tempNode = head;
        //ListNode length
        while (tempNode != null){
            length ++;
            tempNode = tempNode.next;
        }
        if (length / k == 0)
            return head;
        //翻转链表
        ListNode t = null;
        ListNode current = head;
        ListNode next = head.next;
        for (int i = 0; i < k -1; i++) {
            t = next.next;
            next.next = current;
            current = next;
            next = t;
        }
        head.next = reverseKGroup(next, k);
        return current;

    }
}
```