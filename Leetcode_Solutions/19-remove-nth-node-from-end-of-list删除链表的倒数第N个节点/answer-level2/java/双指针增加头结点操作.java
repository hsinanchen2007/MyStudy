### 解题思路
1、给链表增加头结点；
2、双指针遍历，探路的指针先跑N，到达链表结束，操作指针停留在倒数第N + 1个结点。
3、删除倒数第N个结点。

用时0ms击败100%，但是内存消耗倒数5%，不知道消耗在哪里。

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null) {
            return null;
        }
        // 给链表加一个头结点
        ListNode resultNode = new ListNode(0);
        resultNode.next = head;
        ListNode currentNode = resultNode;
        ListNode nthNodeFromEnd = resultNode;
        int count = 0;
        // 双指针筛选倒数第N个结点
        while (currentNode != null) {
            if (count > n) {
                nthNodeFromEnd = nthNodeFromEnd.next;
            }
            currentNode = currentNode.next;
            count++;
        }
        // 去除倒数第N个Node
        if (nthNodeFromEnd != null) {
            nthNodeFromEnd.next = nthNodeFromEnd.next.next;
        }
        return resultNode.next;
    }
}
```