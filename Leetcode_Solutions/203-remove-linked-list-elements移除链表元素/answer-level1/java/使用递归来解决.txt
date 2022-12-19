### 解题思路
使用递归
将当前的链表看成是由 --> head节点 + 后面所有节点组成的短一点的链表 组成
判断head是否满足条件，满足就删除head，return head.next;
不满足就保留head，return head; 

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
    public ListNode removeElements(ListNode head, int val) {
        if(head == null){
            return head;
        }
        head.next = removeElements(head.next,val);
        return head.val == val ? head.next : head;

    }
}
```