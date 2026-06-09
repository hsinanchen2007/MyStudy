### 解题思路
![image.png](https://pic.leetcode-cn.com/5a10f403c86084ddd1852738e0b26a91030dc35bf26f1f1cf8b61cdf11834bb1-image.png)
递归单步操作就是节点的两两交换，交换后返回头结点，代码应该比较清晰
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
        if (head == null || head.next == null)
            return head;
        ListNode prevNode = head;
        ListNode afterNode = head.next;
        ListNode nextNode = head.next.next;
        afterNode.next = prevNode;
        prevNode.next = swapPairs(nextNode);
        return afterNode;
    }
}
```