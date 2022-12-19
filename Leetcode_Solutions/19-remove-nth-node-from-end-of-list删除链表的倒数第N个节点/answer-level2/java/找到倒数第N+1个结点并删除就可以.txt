### 解题思路
此题和查找倒数第K个结点比较相似，要删除倒数第n个结点只需要找到倒数第N+1个结点并删除就可以，但防止出现空指针需要设置一个哑结点。

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
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next=head;
        ListNode  fast = dummyHead;
        ListNode  slow = dummyHead;
        for(int i=0;i<n+1;i++){//快指针先移动N+1个位置
            fast=fast.next;
         }
        while(fast!=null){//快指针指向最后一个节点停下 此时慢指针指向倒数第N+1个结点
            slow=slow.next;
            fast=fast.next;       
         }
        slow.next=slow.next.next;//删除倒数第N个结点
        return dummyHead.next;
    }
}
```