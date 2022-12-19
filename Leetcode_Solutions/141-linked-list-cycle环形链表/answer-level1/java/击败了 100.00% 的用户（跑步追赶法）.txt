### 解题思路
很简单，跑步追赶，需要注意的是跳出循环的情况！

### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        // 判断链表是否有环，其实类似于跑步，双指针跑步，只要前面的能追上后面的就是有环
        if (head == null || head.next == null || head.next.next == null) {
            return false;
        }

        ListNode smallNode = head;
        ListNode bigNode = head.next.next;

        boolean ans = false;
        while (smallNode != null) {
            if (smallNode == bigNode) {
                ans = true;
                break;
            }
            smallNode = smallNode.next;
            if (bigNode.next == null || bigNode.next.next == null) {
                break;
            }

            bigNode = bigNode.next.next;
        }

        return ans;
    }
}
```