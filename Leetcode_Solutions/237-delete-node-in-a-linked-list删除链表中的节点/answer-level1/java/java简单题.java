1.思路就是将要删除节点node的值修改为node.next的值，然后node的下一个节点跨过node.next即可。
```
class Solution {
   public void deleteNode(ListNode node) {
	   node.val = node.next.val;
	   node.next = node.next.next;
   }
}
```
