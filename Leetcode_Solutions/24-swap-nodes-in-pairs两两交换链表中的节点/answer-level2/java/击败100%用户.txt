### 解题思路
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :34.6 MB, 在所有 Java 提交中击败了81.91%的用户

我也不知道该怎么解释……就着注释看吧

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
    public ListNode swapPairs(ListNode head) {
        if(head == null) return null; //null返回null
        if(head.next == null) return head; //下一个节点是null，返回这个节点
        ListNode next = head.next; //下一个节点
        ListNode tmp = head; //临时节点，当前节点
        ListNode nextNext = next.next; //下一个节点的下一个节点
        head = next; 
        head.next = tmp; //更换这个节点和下一个节点
        head.next.next = swapPairs(nextNext); //让原先的下一个节点的下一个节点进行更换操作
        return head;
    }
}
```