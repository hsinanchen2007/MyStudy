### 解题思路
通过两个快慢指针实现，当快指针没有next后停止，慢指针即为所找的中间节点。

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
        ListNode slowPoint = head;
        ListNode quickPoint = head;
        while(quickPoint.next != null && quickPoint.next.next != null){
            slowPoint = slowPoint.next;
            quickPoint = quickPoint.next.next;
        }
        if(quickPoint.next != null){
            slowPoint = slowPoint.next;
        }
        return slowPoint;
    }
}
```