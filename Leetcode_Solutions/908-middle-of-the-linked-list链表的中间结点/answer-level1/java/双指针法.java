### 解题思路
有两个指针:
1.第一个指针代表中间结点指针，每次往后一个结点
2.第二个指针代表尾结点，每次往后两个结点(循环遍历，直到尾结点为空或者尾结点的下一个结点为空

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
    public ListNode middleNode(ListNode head) {

        if (head == null || head.next == null) {
            return head;
        }

        ListNode middle = head;
        ListNode tail = head;
        while (tail != null && tail.next != null) {
            middle = middle.next;
            tail = tail.next.next;
        }

        return middle;
    }
}
```