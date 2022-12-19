### 解题思路
1.构建一个list保存所有的节点值
2.list排序
3.构建新的链表

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        List<Integer> list = new ArrayList<>();
        while (l1 != null) {
            list.add(l1.val);
            l1 = l1.next;
        }
        while (l2 != null) {
            list.add(l2.val);
            l2 = l2.next;
        }
        Collections.sort(list);
        ListNode virtual = new ListNode(-1);
        ListNode head = virtual;
        for (int i = 0; i < list.size(); i++) {
            virtual.next = new ListNode(list.get(i));
            virtual = virtual.next;
        }
        return head.next;
    }
}
```