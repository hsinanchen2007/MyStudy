### 解题思路
解法1：莽夫型

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
    public int[] reversePrint(ListNode head) {
        int linkedListLength = 0;
        ListNode temp = head;
        while (temp != null) {
            temp = temp.next;
            linkedListLength = linkedListLength + 1;
        }
        int[] res = new int[linkedListLength];
        for (int i = 0; i < linkedListLength; i ++) {
            temp = head;
            for (int j = 0; j < linkedListLength - i - 1; j ++) {
                temp = temp.next;
            }
            res[i] = temp.val;
        }
        return res;
    }
}
```