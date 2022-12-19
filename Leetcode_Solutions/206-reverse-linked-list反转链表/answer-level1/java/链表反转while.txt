### 解题思路
反转上一题陷入误区了，之前一直写链表都有存储size，使用for循环，其实这里可以直接用while迭代

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
        ListNode reverseNode = null;
        ListNode tmpNode = head;
        while(tmpNode != null){
            ListNode nextNode = tmpNode.next;
            tmpNode.next = reverseNode;
            reverseNode = tmpNode;
            tmpNode = nextNode;
        }
        return reverseNode;
    }

}
```