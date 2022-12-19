### 解题思路
![image.png](https://pic.leetcode-cn.com/5e45662b0d032fdaa3cda91f7fad21d72786a6b097c88abd2da034bed74305f6-image.png)
当链表长度超过2的时候进入循环，以三个连续链表对象为开始，每次循环将中间节点指向反转


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
        if (head == null) {
            return null;
        }
        if (head.next == null) {
            return head;
        }
        ListNode tempNode1 = head.next;
        if (tempNode1.next == null) {
            head.next = null;
            tempNode1.next = head;
            return tempNode1;
        }
        head.next = null;
        ListNode tempNode2 = tempNode1.next;
        tempNode1.next = head;
        while (tempNode2.next != null) {
            head = tempNode1;
            tempNode1 = tempNode2;
            tempNode2 = tempNode2.next;
            tempNode1.next = head;
        }
        tempNode2.next = tempNode1;
        return tempNode2;
    }
}
```