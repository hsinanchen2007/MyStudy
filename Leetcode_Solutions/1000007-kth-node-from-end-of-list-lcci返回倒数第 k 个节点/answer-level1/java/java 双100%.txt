### 解题思路
此处撰写解题思路
参考大神的思路写的代码
两个指针，一个先往前走k步，另一个再开始走，第一个到头后，第二个到目标
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
    public int kthToLast(ListNode head, int k) {
        ListNode p = head;
        for (int i = 0 ; i < k ; i++) {
            p = p.next;
        }
        while (p != null) {
            head = head.next;
            p = p.next;
        }
        return head.val;
    }
}
```