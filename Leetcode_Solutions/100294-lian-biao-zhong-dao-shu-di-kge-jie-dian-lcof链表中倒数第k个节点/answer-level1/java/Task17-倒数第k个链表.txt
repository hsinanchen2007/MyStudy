### 解题思路
- 一次遍历即可
- 不需要遍历，利用双指针，让后一个指针先走k-1步即可。

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
    public ListNode getKthFromEnd(ListNode head, int k) {
        // 利用双指针，不需要遍历，先让一个指针走k-1步即可。
        ListNode prev = head;
        ListNode last = head;

        for (int i = 0; i < k-1; i++) {
            if (last.next == null) {
                return null;
            }
            last = last.next;
        }

        while(last.next != null) {
            prev = prev.next;
            last = last.next;
        }

        return prev;

        // 一次遍历
        ListNode temp = head;
        int count = 0;

        while(temp != null) {
            temp = temp.next;
            count++;
        }

        if (k > count || k <= 0) {
            return null;
        }
        
        for (int i = 0; i < count - k; i++) {
            head = head.next;
        }

        return head;

    }
}
```