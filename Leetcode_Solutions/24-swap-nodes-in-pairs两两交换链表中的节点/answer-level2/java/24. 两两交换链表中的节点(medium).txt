### 解题思路
1. 递归法(本题为递归法的典型应用)
    对于递归法而言，需要关注的最关键三个要素：返回值，调用单元的操作和终止条件。
    a) 返回值：交换完成后的子链表
    b) 调用单元：设置需要调换的两个节点为firstNode和secondNode，firstNode用来连接后面交换完成的子链表，secondNode连接firstNode，完成本轮交换操作。
    c) 终止条件：firstNode或者secondNode为空，对应当前没有节点或者剩下最后一个单独的节点的情况。
2. 迭代法
    a) 将链表编号分为奇数编号的节点和偶数编号的节点。(要完成的操作是将对应节点两两互换)
    b) 交换两个节点。
    c) 维护一个preNode节点，preNode.next指向交换后的头节点。

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

        // If the list has no node or has only one node left.
        if ((head == null) || (head.next == null)) {
            return head;
        }

        // Nodes to be swapped
        ListNode firstNode = head;
        ListNode secondNode = head.next;

        // Swapping
        firstNode.next  = swapPairs(secondNode.next);
        secondNode.next = firstNode;

        // Now the head is the second node
        return secondNode;
    }
}


```
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

        // Dummy node acts as the prevNode for the head node
        // of the list and hence stores pointer to the head node.
        ListNode dummy = new ListNode(-1);
        dummy.next = head;

        ListNode prevNode = dummy;

        while ((head != null) && (head.next != null)) {

            // Nodes to be swapped
            ListNode firstNode = head;
            ListNode secondNode = head.next;

            // Swapping
            prevNode.next = secondNode;
            firstNode.next = secondNode.next;
            secondNode.next = firstNode;

            // Reinitializing the head and prevNode for next swap
            prevNode = firstNode;
            head = firstNode.next; // jump
        }

        // Return the new head node.
        return dummy.next;
    }
}

```