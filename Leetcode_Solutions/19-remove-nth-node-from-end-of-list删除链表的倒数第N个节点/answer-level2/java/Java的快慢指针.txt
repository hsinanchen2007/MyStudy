### 解题思路
看了评论，然后自己写了一遍快慢指针，需要特别注意一下边界值
大概的思路就是让一个指针先走，等到两个指针相隔n的时候另一个指针再开始走，直到快的那个指针的next为null的时候，那么慢的那个指针的next就是我们需要删除的那个一个

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
 // 只有一个直接返回
        if (head.next == null) {
            return null;
        }
        // 快慢指针
        ListNode i = null;
        ListNode j = head;
        ListNode node = head;
        int k = 1;
        while (node.next != null) {
            j = node;
            if (j.next == null) {
                break;
            }
            if (k >= n) {
                if (i == null) {
                    i = head;
                } else {
                    i = i.next;
                }
            }
            k++;
            node = node.next;
        }
        if (i == null){
            return head.next;
        }
        ListNode delete = i.next;
        ListNode next = delete.next;
        i.next = next;
        delete.next = null;
        return head;
    }
}
```