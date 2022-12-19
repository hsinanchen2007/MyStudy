### 解题思路
链表逆序可以看做左右互换，但是互换之前，需要通过一个临时变量存储右边节点的地址。
1. 迭代
    1.存储右边节点的地址
    2.当前节点的右边节点替换为左边节点
    3.左边节点右移
    4.当前节点右移

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
    public ListNode reverseList(ListNode head) {
       ListNode pre = null;
       ListNode curr = head;
        while(curr != null){
            ListNode next = curr.next;
            curr.next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
}
```