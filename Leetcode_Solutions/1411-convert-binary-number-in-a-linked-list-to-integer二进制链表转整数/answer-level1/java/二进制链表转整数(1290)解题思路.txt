### 解题思路
以数字5为例，5的二进制为101。如题，链表的形式则为1->0->1。遍历这个链表，结果如下

第一个节点1： result = 0 + 1; result为1
第二个节点0： result = (result * 2) + 0; result为2
第三个节点1： result = (result * 2) + 1; result为5

根据这个规则编写代码即可
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
    public int getDecimalValue(ListNode head) {
        int res = 0;
        while(head != null)
        {
            res = res *2 + head.val;
            head = head.next;
        }
        return res;
    }
}
```