### 解题思路

十进制数 = 百位 * 2^2 + 十位 * 2^1 + 个位 * 2^0

递归深度乘2乘val，得出单个位置的十进制数，最后加起来

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
        int nums = 0;
        while (head!=null){
            nums += rec(head) * head.val;
            head=head.next;
        }
        return nums;
    }

    public int rec(ListNode node){
        if (node.next == null)
            return 1;
        return 2 * rec(node.next);
    }
}
```