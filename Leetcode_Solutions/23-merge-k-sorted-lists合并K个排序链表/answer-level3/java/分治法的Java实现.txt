### 解题思路
解题思路见官方题解。
自己犯的两个错误，一个是合并两个链表时，不需要new node出来，直接next指向就可以了。另一个问题是middle计算时记得加上start值。

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
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        
        return mergeKLists(lists, 0, lists.length - 1);
    }

    private ListNode mergeKLists(ListNode[] lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
                
        int middle = start + (end - start) / 2;
        ListNode leftNode = mergeKLists(lists, start, middle);
        ListNode rightNode = mergeKLists(lists, middle + 1, end);

        // merge操作
        ListNode mergeDummy = new ListNode(0);
        ListNode tempNode = mergeDummy;
        while (leftNode != null && rightNode != null) {
            if (leftNode.val < rightNode.val) {
                tempNode.next = leftNode;
                tempNode = tempNode.next;
                leftNode = leftNode.next;
            } else {
                tempNode.next = rightNode;
                tempNode = tempNode.next;
                rightNode = rightNode.next;
            }
        }

        if (leftNode != null) {
            tempNode.next = leftNode;
        }

        if (rightNode != null) {
            tempNode.next = rightNode;
        }

        return mergeDummy.next;
    }
}
```