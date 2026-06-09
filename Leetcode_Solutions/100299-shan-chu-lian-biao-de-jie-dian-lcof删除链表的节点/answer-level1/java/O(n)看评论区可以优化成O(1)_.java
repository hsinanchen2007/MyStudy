### 解题思路
此处撰写解题思路
O(n)时间都是100%吗？
执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
38.6 MB
, 在所有 Java 提交中击败了
100.00%
的用户
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
    public ListNode deleteNode(ListNode head, int val) {
        ListNode node = head;
        if (head.val == val){ 
            head = head.next;
            return head;
        }
        while (node.next.val != val){
            node = node.next;
        }
        node.next = node.next.next;
        return head;
    }
}
```