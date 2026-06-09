### 解题思路
递归
两两交换，故每次只需要考虑相连两个数据交换即可，然后返回交换的结果（交换后的第一个元素，因为前面的next需要指向后面交换完成的first）

执行结果：0ms       100%
         37.6MB     5%

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
        if (head == null) {
            return null;
        }
        return swapPairs(head, head.next);
    }

    public static ListNode swapPairs(ListNode preNode, ListNode currentNode) {
        if (preNode == null) {
            return null;
        }
        if (currentNode == null) {
            return preNode;
        }
        preNode.next = swapPairs(currentNode.next, currentNode.next == null ? null : currentNode.next.next);
        currentNode.next = preNode;
        return currentNode;
    }
}
```