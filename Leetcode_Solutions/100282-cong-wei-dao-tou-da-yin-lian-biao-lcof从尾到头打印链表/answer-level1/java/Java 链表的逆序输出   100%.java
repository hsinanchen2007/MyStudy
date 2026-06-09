### 解题思路
链表的逆序输出其实可以借助于栈实现，这里我是先统计链表的节点个数，然后创建对应大小的数组。
从head开始遍历，数据存储从后到前开始。

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
        if (head == null) {
            return new int[0];
        }

        ListNode p = head;
        int count = 0;
        while (p != null) {
            count++;
            p = p.next;
        }
        int[] result = new int[count];
        p = head;
        while (p != null) {
            result[--count] = p.val;
            p = p.next;
        }

        return result;
    }
}
```