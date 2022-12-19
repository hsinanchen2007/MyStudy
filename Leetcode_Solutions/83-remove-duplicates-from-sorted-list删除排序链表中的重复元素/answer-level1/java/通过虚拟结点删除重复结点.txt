### 解题思路
![微信截图_20191224162030.png](https://pic.leetcode-cn.com/197b6defb587ab8f2fda9a64812e98bdb7b5747682df5d09631ef325edad2a1f-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20191224162030.png)
虚拟一个头结点，定义两个指针pre和cur , 分别指向头结点和当前结点。循环遍历，如果检测到当前指针的值和上一个指针的值相等，则将上一个指针指向当前结点的一个值。否则只需要移动将上个指针移动到当前位置。最后，当前位置指针往后移动一位。
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
        public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode pre = new ListNode(-1);
        pre.next = head;
        ListNode cur = head;
        while (cur != null) {
            if (pre.val == cur.val) {
                pre.next = cur.next;
            } else {
                pre = cur;
            }
            cur = cur.next;
        }
        return head;
    }
}
```