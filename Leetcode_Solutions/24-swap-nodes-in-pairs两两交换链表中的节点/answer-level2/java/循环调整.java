### 解题思路

循环标记和调整

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
    // public ListNode swapPairs(ListNode head) {
    //     // 当前节点数为0或者1时, 不足以交换
    //     if(head == null || head.next == null) return head;
    //     // 节点数大于1, 交换node1和node2
    //     ListNode node1 = head;
    //     ListNode node2 = head.next;
    //     // node1的后驱指向node2之后的节点
    //     node1.next = swapPairs(node2.next);
    //     // node2的后驱指向node1
    //     node2.next = node1;
    //     // 返回node2节点
    //     return node2;
    // }
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(-1);
        ListNode pre = dummy;
        pre.next = head;
        ListNode cur = head;
        while(cur!=null && cur.next != null){
            ListNode node1 = cur; 
            ListNode node2 = cur.next;
            cur = cur.next.next;
            // 前驱的下一个节点为node2
            pre.next = node2;
            // node1后驱为node2的后驱
            node1.next = node2.next;
            // node2后驱变为node1
            node2.next = node1;
            // 然后调整下一轮的前驱节点
            pre = node1;
        }
        ListNode p = dummy;
        while(p != null){
            System.out.println(p.val);
            p = p.next;
        }
        return dummy.next;
    }

}
```