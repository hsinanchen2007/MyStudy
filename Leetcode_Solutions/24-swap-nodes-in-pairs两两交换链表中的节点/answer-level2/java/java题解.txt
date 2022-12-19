执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
40.2 MB
, 在所有 Java 提交中击败了
5.09%
的用户

### 解题思路
分解题目其实内部就是反转链表的变种，注意保存前驱结点

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
        if (head == null || head.next == null){
            return head;
        }
        ListNode dummy = new ListNode(0);
        ListNode cacheNode = null;
        while (head != null && head.next != null){
            ListNode fast = head.next;
            ListNode curr = fast.next;
            head.next = curr;
            fast.next = head;
            if(dummy.next == null){
                dummy.next = fast;
            }else {
                cacheNode.next = fast;
            }
            cacheNode = head;
            head = head.next;
        }
        return dummy.next;
    }
}
```