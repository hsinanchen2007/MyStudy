我觉得官方题解的答案漏了，删除的节点是最后一个的情况；下面是我的solution

```dart
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        if(null==node)
            return;
        if(null==node.next){
            node=null;
            return;
        }
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
```
