```
class Solution {
    public void deleteNode(ListNode node) {
        ListNode demo = node.next;
        node.val = demo.val;
        node.next = demo.next;
    }
}
```
