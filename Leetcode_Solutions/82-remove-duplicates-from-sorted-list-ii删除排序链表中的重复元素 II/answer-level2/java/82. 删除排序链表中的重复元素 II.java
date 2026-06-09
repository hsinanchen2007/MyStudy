### 解题思路
创建一个新的链表,顺序遍历原有的链表,查找不重复的节点加到新链表里面去
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

    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode(0);
        ListNode preNode = null;
        ListNode currentNode = head;

        ListNode lastNode = dummy;
        while (currentNode != null) {
            if (isNotDuplicates(currentNode, preNode)) {
                lastNode.next = new ListNode(currentNode.val);
                lastNode = lastNode.next;
            }
            preNode = currentNode;
            currentNode = currentNode.next;
        }
        return dummy.next;
    }

    private boolean isNotDuplicates(ListNode currentNode, ListNode preNode) {
        if (preNode != null && currentNode.val == preNode.val) {
            return false;
        }
        if (currentNode.next != null && currentNode.val == currentNode.next.val) {
            return false;
        }
        return true;
    }

}
```