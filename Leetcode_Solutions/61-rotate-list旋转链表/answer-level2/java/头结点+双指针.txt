### 解题思路
头结点化简代码,可以遍历到newHead前一个节点；
用双指针节点一个遍历到末尾，一个留下k个未遍历；
完成两次遍历后，将该链接的节点连起来就行了。

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
    public ListNode rotateRight(ListNode head, int k) {
        if(k == 0 || head == null) return head;
        ListNode prev = new ListNode(0);
        prev.next = head;
        ListNode temp = prev;
        int len = 0;
        while(prev.next != null){
            prev = prev.next;
            len++;
        }
        k = k % len;
        if(k == 0) return head;
        for(int i = 0; i < len-k; i++){
            temp = temp.next;
        }
        ListNode newHead = temp.next;
        temp.next = null;
        prev.next = head;
        return newHead;
    }
}
```