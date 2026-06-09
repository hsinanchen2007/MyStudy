### 解题思路
1.非空链表，直接在入口处判空，返回。
2.使用两个引用来分别遍历这两个链表，对相同深度的节点的值以及进位值进行相加操作，利用除法（/）得到当前节点的值，然后利用取模（%）得到进位值供下个节点使用。

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
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null || l2 == null)
            return null;
        ListNode cache1 = l1, cache2 = l2;
        int addNode = 0;
        int carry = 0;
        ListNode answer = null;
        ListNode cacheNode = null;
        while (cache1 != null || cache2 != null || carry > 0) {
            if (cache1 != null && cache2 != null) {
                addNode = cache1.val + cache2.val + carry;
                cache1 = cache1.next;
                cache2 = cache2.next;
            } else if (cache1 == null && cache2 != null) {
                addNode = cache2.val + carry;
                cache2 = cache2.next;
            } else if (cache1 != null) {
                addNode = cache1.val + carry;
                cache1 = cache1.next;
            } else {
                addNode = carry;
            }
            if (answer == null) {
                answer = cacheNode = new ListNode(addNode % 10);
            } else {
                cacheNode.next = new ListNode(addNode % 10);
                cacheNode = cacheNode.next;
            }
            carry = addNode / 10;
        }
        return answer;
    }
}
```