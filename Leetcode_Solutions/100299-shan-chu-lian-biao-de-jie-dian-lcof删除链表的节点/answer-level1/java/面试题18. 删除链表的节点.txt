### 解题思路
定义两个相邻的指针，一前一后，前面的锁定值的位置，后面的刚好是操作节点的前一节点，进行删除操作。

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
        ListNode node=head;
        ListNode result=new ListNode(0);
        result.next=head;
        ListNode pre=result;
        while(node!=null&&node.val!=val){
            result=result.next;
            node=node.next;
        }
        if(node!=null)result.next=node.next;
        return pre.next;
    }
}
```