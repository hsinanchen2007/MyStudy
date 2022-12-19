### 解题思路
可以用双指针解决：
    1. 定义一个ListNode：pre，pre.next=head，只是为了记录头节点的位置，因为可能被删除的是头节点
    2. 定义两个指针start,end，都指向pre;
    3. 先把start向前移动n个节点
    4. 然后同时移动start和end，当start.next==null时，结束循环，此时end.next就是我们要删除的节点
    5. 直接把end.next=end.next.next，删除倒数第N个节点
    6. 最后返回pre.next

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
        ListNode pre=new ListNode(0);
        pre.next=head;
        ListNode start=pre;
        ListNode end=pre;
        while(start.next!=null&&n>0){
            start=start.next;
            n--;
        }
        while(start.next!=null){
            start=start.next;
            end=end.next;
        }
        end.next=end.next.next;
        return pre.next;
    }
}
```