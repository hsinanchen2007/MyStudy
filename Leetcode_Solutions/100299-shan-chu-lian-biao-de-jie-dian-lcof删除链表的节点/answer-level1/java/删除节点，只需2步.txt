### 解题思路
使用虚拟头结点，避免删除头节点的判断；
识别判断循环中止的条件，检查是否执行删除操作；
双指针，保留上个节点的引用；
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
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        ListNode cur = head;
        ListNode pre = dummyHead;
        while(cur!=null&&cur.val!=val){
            pre = pre.next;
            cur = cur.next;
        }
        if(cur!=null){
            pre.next = cur.next;
            cur.next = null;
        }
        return dummyHead.next;
    }
}
```