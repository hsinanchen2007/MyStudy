### 解题思路
没啥思路，搞两个flag就可以了，一个两个flag之间相差n个元素就好了。
因为是删除链表中的元素，所以我们设置一个虚拟节点使其在头节点前面，当后面的flag元素的下一个为空的时候，说明已经到最后的，这时候删除前面的flag后面的元素就可以了


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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummyHead  = new ListNode(-1);
        dummyHead.next = head;
        ListNode cur = dummyHead;
        ListNode removeNode = dummyHead;
        for(int i=0; i<n; i++){// 使得两个flag相差n
            cur = cur.next;
        }
        while(cur.next != null){
            cur = cur.next;
            removeNode = removeNode.next;
        }
        removeNode.next = removeNode.next.next;
        return dummyHead.next;
        
    }
}
```