### 解题思路
本题和`82`题思路一样都是**创建两个空链结点**来链接两种情况的元素，最后再合并为一条新链

- 首先对链表头结点`head`判空

- 然后**创建两个空链结点**链接题目中的**奇数位置元素**和**偶数位置元素**

- 每次将**偶数**位置元素**断链**接到新的偶数链结点后面，最后再**将奇数链最后一个结点与偶数链的头结点相连**即可。

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
    public ListNode oddEvenList(ListNode head) {
        if (head == null) {
            return head;
        }
        // 创建奇 (odd) 偶 (even) 链表结点分别链接奇数位置元素和偶数位置元素
        ListNode odd = head;
        ListNode even = odd.next;
        // 固定偶数链的第一个结点
        ListNode evenHead = even;
        // 将偶数位置元素断链接在 evenHead 后面
        while (even != null && even.next !=null) {
            odd.next = even.next;
            odd = odd.next;
            even.next = odd.next;
            even = even.next;
        }
        // 最后再用奇数链的最后一个结点连上偶数链的头结点即可
        odd.next = evenHead;
        return head;
    }
}
```