### 解题思路
让链表首尾相连构成一个环形链表，假设链表长度为len，用两个指针head、end分别指向链表的首尾，循环判断head + i 和 end + len - i，指向的元素是否相等

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
    public boolean isPalindrome(ListNode head) {
        if (head == null) {
            return true;
        }

        int len = 1;
        ListNode end = head;
        while (end.next != null) {
            end = end.next;
            len++;
        }

        if (end == head) {
            return true;
        }

        end.next = head;

        ListNode p1 = head;
        ListNode p2 = end;

        if(head.val != end.val){
            return false;
        }

        int count1 = 0;
        int count2 = 0;
        for (int i = 1; i < len / 2; i++) {
            count1 = 0;
            count2 = 0;
            while (count1 != i) {
                count1++;
                p1 = p1.next;
            }

            while (count2 != len - i) {
                count2++;
                p2 = p2.next;
            }

            if (p1.val != p2.val) {
                return false;
            }

            p1 = head;
            p2 = end;
        }

        return true;
    }
}
```