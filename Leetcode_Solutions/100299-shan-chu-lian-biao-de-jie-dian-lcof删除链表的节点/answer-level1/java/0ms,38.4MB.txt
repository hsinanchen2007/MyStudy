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
    public ListNode deleteNode(ListNode head, int val) {
        ListNode node = head;
        if(head.val==val){
            node = head.next;
            return node;
        }
        while(head!=null){
            if(head.next.val==val){
                head.next = head.next.next;
                break;
            }
            head = head.next;
        }
        return node;

    }
}
```