### 解题思路
此处撰写解题思路

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
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) return null;
        int len = lists.length;
        while (len > 1) {
            int index = 0;
            while (index < (len >> 1)) {
                int other = len - 1 - index;
                //System.out.println("index:" + index + ", other:" + other);
                lists[index] = mergeTwoLists(lists[index], lists[other]);
                index ++;
            }
            len = (len + 1) >> 1;
            //System.out.println("len:" + len);
        }
        return lists[0];
    }

    // 21. 合并两个有序链表
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        if (l1.val <= l2.val) {
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        } else {
            l2.next = mergeTwoLists(l2.next, l1);
            return l2;
        }
    }
}
```