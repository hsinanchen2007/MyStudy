### 解题思路
后知后觉回来编辑注释，链表是有序的，我想多了。。。。。。。。
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
    public ListNode deleteDuplicates(ListNode head) {
    if(head == null)
        return null;
    Set<Integer>set = new HashSet<>();
    set.add(head.val);
    ListNode left = head;
    ListNode right = head;
    while(right != null)
    {
        while(right != null && set.contains(right.val))
        {
            right = right.next;
        }
        if(right != null)
            set.add(right.val);
        left.next = right;
        left = right;
        if(right != null)
            right = right.next;
    }

    return head;
    }
}
```