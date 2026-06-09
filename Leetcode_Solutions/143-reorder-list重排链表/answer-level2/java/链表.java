### 解题思路
用栈保存，然后依次弹栈来保存节点。

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
        int len = 0;
        ListNode tail = head;
        
        while(tail != null){
            len += 1;
            tail = tail.next;
        }
        if(len < 3)
            return;
        
        tail = head;
        Stack<ListNode> stack = new Stack<>();
        for(int i = 0; i < len; i++){
            stack.push(tail);
            tail = tail.next;
        }
        
        //弹栈次数的len / 2, 如果len是奇数，则让弹出之后的next=null;如果len是偶数，则让弹出之后连接节点的next=null

        tail = head;
        ListNode tmp = null;
        for(int i = 0; i < len / 2; i++){
            tmp = stack.pop();
            tmp.next = tail.next;
            tail.next = tmp;
            tail = tmp.next;
        }
        if(len % 2 == 0){
            tmp.next = null;
        }
        else{
            tail.next = null;
        }
    }
}
```