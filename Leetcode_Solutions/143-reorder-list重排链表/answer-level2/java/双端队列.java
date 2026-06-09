### 解题思路
虽然效率不高，但是易于理解。

首先，将所有链表中所有节点入队。
然后，交替从队头队尾取节点插入链表中。
最后，将链表尾部的节点置空。

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
    public void reorderList(ListNode head) {
        if(head == null || head.next == null) return;
        ListNode cur = head.next;
        Deque<ListNode> deque = new ArrayDeque();
        while(cur != null){
            deque.add(cur);
            cur = cur.next;
        }
        boolean flag = true;
        cur = head;
        while(!deque.isEmpty()){
            if(flag){
                cur.next = deque.removeLast();
                cur = cur.next;
                flag = !flag;
            }
            else{
                cur.next = deque.removeFirst();
                cur = cur.next;
                flag = !flag;
            }
        }
        cur.next = null;
    }
}
```