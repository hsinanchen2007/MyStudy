### 解题思路
此处撰写解题思路

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
        if(k == 0){
            return head;
        }
        if(head == null){
            return null;
        }
        if(head.next == null){
            return head;
        }
        
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;
        int size = 0;
        ListNode cur = dummyHead;
        while(cur.next != null){
            cur = cur.next;
            size++;
        }
        if(k > size){
            if( k % size == 0){
                return head;
            }
            k = k % size;
        }
        ListNode p = dummyHead;
        ListNode q = dummyHead;
        for(int i = 0; i < (size - k); i++){
            p = p.next;//走到了移动的节点的前一个节点
        }
        ListNode newHead = p.next;
        ListNode res = newHead;
        p.next = null;
        while(newHead.next != null){
            newHead = newHead.next;
        }
        newHead.next = q.next;
        return res;

    }
}
```