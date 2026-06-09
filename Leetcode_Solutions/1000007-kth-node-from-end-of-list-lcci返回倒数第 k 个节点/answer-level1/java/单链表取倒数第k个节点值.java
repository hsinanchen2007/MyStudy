### 解题思路

依次遍历单链表，并将每个链表节点存入map中，key存放表示节点位置的字符串i，value存放该节点的值。

遍历到节点末尾后，用 i - k得到需要节点的位置，从map中取出即可。



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
        if (head == null) {
            return 0;
        }
        Map<String, Integer> map = new HashMap<>(16);
        int i = 1;
        while (head != null) {
            map.put(String.valueOf(i), head.val);
            head = head.next;
            i++;
        }
        return k > i ? 0 : map.get(String.valueOf(i - k));
    }
}
```