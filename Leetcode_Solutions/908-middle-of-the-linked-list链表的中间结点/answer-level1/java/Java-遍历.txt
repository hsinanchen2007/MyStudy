### 解题思路
先遍历一遍算出链表长度，然后取中间值，再从头遍历一遍到中间链表节点。

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
        int length = 0;
        ListNode start = head;
        while(start!=null){
            start = start.next;
            length++;
        }
        int mid = length/2+1;
        System.out.println(mid);
        int end = 1;
        ListNode middleNode = head;
        while(end!=mid){
            middleNode = middleNode.next;
            end++;
        }
        return middleNode;
    }
}
```