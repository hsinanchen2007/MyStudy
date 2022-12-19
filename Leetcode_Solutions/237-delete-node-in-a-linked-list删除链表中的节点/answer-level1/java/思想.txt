### 解题思路
此处撰写解题思路
我的思路:
    因为不知道上一个节点的next，所以当前的节点不能直接删除，我采用的方式是将下一个的值赋值给当前的这个值，然后
通过这个值的next连接到下一个的next就行了;
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
        temp.val=node.next.val;
        temp.next=temp.next.next;
    }
}
```