### 解题思路
此处撰写解题思路

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
        if(head == null) return head;

        ListNode cur = head;
        int count = 1;
        int length = 1;
        while(cur != null){
            cur = cur.next;
            length++;
        }

        while(count <= length){
            if(count == length - k){
                return head;
            }
            head = head.next;
            count++;
        }

        return head;
    }
}
```