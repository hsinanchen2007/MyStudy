### 解题思路
题目给定了需要反转的位置区间，所以我们需要考虑反转之后我们如何连接这个链表。所以我们大致可以拆成两个步骤来看
1. 找到给定区间的前一个和后一个，记录他们的位置
2. 反转区间中的节点，之后连接链表。

因为题目中要求使用一趟扫描完成反转，那么我们根据既定的思路拆成两部分遍历：
1. 第一部分，从头节点遍历到开始位置的前一个位置
2. 第二部分从开始位置遍历到结束的位置，并记录结束位置的下一个位置

致此，我们使用一趟扫描记录了两个节点。

另外注意：由于题目中`1 ≤ m ≤ n ≤ 链表长度。` 是这样给定的区间，这说明我们很有可能出现反转链表头节点的情况，这样的话我们就需要引入一个哑节点让头节点于其他节点操作一致。

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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode result = new ListNode(0);
        result.next = head;
        
        ListNode prev = result, endNext = result, p = result;
        
        for(int i = 0; i < m - 1; i++)
        {
            p = p.next;
        }
        prev = p;
        ListNode begin = prev.next;
        
        for(int j = 0; j <= n - m; j++)
        {
            p = p.next;
        }
        endNext = p.next;
        
        prev.next = reverse(begin, p);
        begin.next = endNext;
        
        return result.next;
    }
    
    public ListNode reverse(ListNode head, ListNode tail)
    {
        if(head == tail)
            return head;
        
        ListNode cur = reverse(head.next, tail);
        head.next.next = head;
        return cur;
    }
}
```