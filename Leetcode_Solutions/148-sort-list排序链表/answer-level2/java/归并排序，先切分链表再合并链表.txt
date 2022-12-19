### 解题思路
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
    public ListNode sortList(ListNode head) {
        return listMergeSort(head);
    }

    private ListNode listMergeSort(ListNode node) {
        if (node == null || node.next == null) {
            return node;
        }
        ListNode midNode = splitListIntoTwoPiecesAndReturnSecondHead(node);
        ListNode res1 = listMergeSort(node);
        ListNode res = listMergeSort(midNode);
        return mergeTwoSortedList(res, res1);
    }

    private ListNode splitListIntoTwoPiecesAndReturnSecondHead(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode fastNode = head;
        ListNode slowNode = head;
        while (fastNode != null && fastNode.next != null && fastNode.next.next != null) {
            fastNode = fastNode.next.next;
            slowNode = slowNode.next;
        }
        ListNode res = slowNode.next;
        slowNode.next = null;
        return res;
    }

    private ListNode mergeTwoSortedList(ListNode node1, ListNode node2) {
        if (node1 == null) {
            return node2;
        }
        if (node2 == null) {
            return node1;
        }
        if (node1.val < node2.val) {
            ListNode res = mergeTwoSortedList(node1.next, node2);
            node1.next = res;
            return node1;
        } else {
            ListNode res = mergeTwoSortedList(node1, node2.next);
            node2.next = res;
            return node2;
        }
    }
}
```