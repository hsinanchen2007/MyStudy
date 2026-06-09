### 解题思路
这也能百分百吗。。这题挺简单的，由于单链表的特殊性我们无法从后往前遍历，因此我们反其道而行之，首先计算该链表长度，并减去给定的倒数的数，将该值作为head移动的次数，依次移动head，次数达到给定值，则head刚好移动到待取值，返回该节点的值即可。

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
        ListNode current = head;
        int length = 0;
        while(current!=null) {
            length++;
            current = current.next;
        }
        length = length-k;
        for(int i = 0;i<length;i++) {
            head = head.next;
        }
        return head.val;
    }
}
```