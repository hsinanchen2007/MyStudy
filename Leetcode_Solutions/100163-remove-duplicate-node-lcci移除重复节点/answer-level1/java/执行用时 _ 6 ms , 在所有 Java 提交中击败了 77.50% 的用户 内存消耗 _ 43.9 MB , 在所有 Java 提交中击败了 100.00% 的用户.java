### 解题思路
本题利用了集合的特性，首先我们利用集合依次存储节点的数值，并依次比较，如果重复的值出现，直接直接把该重复的值的节点的前一个节点指向该节点的下一个节点，注意，本题的哨兵节点与当前节点是不断变化的，二者为一前一后关系。

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
    public ListNode removeDuplicateNodes(ListNode head) {
        ListNode current = head;
        ListNode prev = new ListNode(0);
        prev.next = head;
        Set<Integer> set = new HashSet<Integer>();
        while(current!=null) {
            if(!set.contains(current.val)) {
                set.add(current.val);
                prev = current;
            }else {
                prev.next = current.next;
            }
            current = current.next;
        }
        return head;
    }
}
```