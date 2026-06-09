### 解题思路
设计链表的题，稍微难点儿的题都要用到双指针，两个指针交替完成遍历整个链表。
更一般地，数组和链表这种线性表的很多题都可以用双指针解决，这是思考的大方向。

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
    public ListNode reverseList(ListNode head) {
        ListNode node = head;
        ListNode result = null;
        while(node != null){
            ListNode temp = node.next;
            node.next = result;
            result = node;
            node = temp;
        }
        return result;
    }

}
```