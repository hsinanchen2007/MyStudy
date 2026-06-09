### 解题思路
此处撰写解题思路
我的思想：
  在这里我们并不知道前面一个的节点的下一个next，如果将当前的删除掉那么链表就会断开的！
所以我们可以将当前节点的下一个的值赋值给当前的值，然后用当前的值直接链接到下一个的下一个的next，就ok!
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
    public void deleteNode(ListNode node) {
      ListNode temp=node;

      temp.val=temp.next.val;

      temp.next=temp.next.next;

    }
}
```