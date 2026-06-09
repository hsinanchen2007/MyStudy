### 解题思路
奇指针-head
偶指针-head.next
然后每个指针走两步，连接即可得到两个指针列表
奇指针尾部与偶指针头部连接
返回head即可

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
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        //奇偶指针
        ListNode odd   =  head;//奇指针
        ListNode even  =  head.next;//偶指针

        //偶指针头节点
        ListNode evenHead = even;

        while (odd.next != null && even.next != null) { 
            //奇节点下一个节点
            ListNode oddNext = odd.next.next;
            //偶节点下一个节点
            ListNode evenNext = even.next.next;
            odd.next  = oddNext;
            even.next = evenNext;
            odd  = oddNext;
            even = evenNext;
        }

        odd.next = evenHead;

        return head;
    }
}
```