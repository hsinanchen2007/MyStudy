### 解题思路
这题类似于二进制转十进制，唯一区别在于我们是从链表节点中取值，由于单链表的特殊性，我们无法从后往前遍历，只有从前往后。

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
        int sum = 0;
        while(head!=null) {
            sum = sum*2+head.val;
            head = head.next;
        }
        return sum;
    }
}
```