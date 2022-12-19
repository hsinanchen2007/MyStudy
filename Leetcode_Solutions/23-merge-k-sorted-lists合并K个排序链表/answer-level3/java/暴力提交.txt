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
        ListNode newHead = new ListNode(0);
        ListNode tail = newHead;
        int length = lists.length;
        while (needMerge(lists)) {
            int min = Integer.MAX_VALUE;
            int minIndex = 0;
            for (int i = 0; i < length; i++) {
                if (lists[i] != null) {
                    if (lists[i].val  < min) {
                        min = lists[i].val;
                        minIndex = i;
                    }
                }
            }
            ListNode temp = lists[minIndex];
            lists[minIndex] = temp.next;
            temp.next = null;
            tail.next = temp;
            tail = tail.next;
        }
        return newHead.next;
    }

    public boolean needMerge(ListNode[] lists) {
        boolean flag = false;
        int length = lists.length;
        for (int i = 0; i < length; i++) {
            if (lists[i] != null) {
                return true;
            }
        }
        return flag;
    }
}
```