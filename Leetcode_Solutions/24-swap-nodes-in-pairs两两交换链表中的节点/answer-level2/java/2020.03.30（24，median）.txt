### 解题思路
本题思路就是定义交换指针，保证交换的元素不会断链

- 在创建`dummy`带头结点的基础上，再**创建三个指针**用来完成交换元素

- 交换过程中一定要**保证**每个元素都**不能断链**，每交换完一次**记得移动指针**便于下次交换

- 最后返回`dummy`结点后面元素即可。

### 代码

```java []
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
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode pre = dummy;
        ListNode cur = head;
        // 判断数据不为 null 才能执行
        while (cur != null && cur.next != null) {
            ListNode pNext = cur.next;
            // 交换第一批元素
            pre.next = pNext;
            cur.next = pNext.next;
            pNext.next = cur; 
            // 交换过后移动指针便于下次交换    
            pre = cur;
            cur = cur.next;
        }
        return dummy.next;
    }
}
```