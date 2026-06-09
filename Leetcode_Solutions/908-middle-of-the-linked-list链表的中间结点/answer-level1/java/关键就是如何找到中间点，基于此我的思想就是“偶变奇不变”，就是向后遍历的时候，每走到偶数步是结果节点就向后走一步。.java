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
    public ListNode middleNode(ListNode head) {
        ListNode resultNode = head;
        boolean even = false;
        while(head != null){
            head = head.next;
            if(even){
                resultNode = resultNode.next;
            }
            even = !even;
        }
        return resultNode;
    }
}
```