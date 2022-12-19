### 解题思路
![image.png](https://pic.leetcode-cn.com/d42c249af33b10c231c8609ba49261eb81c84148c94814e105c8c84e9134783d-image.png)


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
    /**
     * 0 1 -> 0
     * 2 3 -> 1
     * 4 5 -> 2
     * 6 7 -> 3
     * 8   -> 4
     */
    public ListNode mergeKLists(ListNode[] lists) {
         int length = lists.length;
        if (length == 0) {
            return null;
        }
        while (length > 1) {
                //如果是奇数的情况
            for (int i = 0; i < length; i += 2) {
                if (i + 1 == length) {
                    lists[i / 2] = lists[i];
                } else {
                    //直接将合并后的值赋值给当前数组，根据上面的注释可以看出，位置刚好是i的一半
                    lists[i / 2] = combineTwo(lists[i], lists[i + 1]);
                }
                    //每一遍合并完后，length减半，又重头开始
                if (i + 1 == length || i + 1 == length - 1) {
                    length = i / 2 + 1;
                }
            }
        }
        return lists[0];
    }
    private ListNode combineTwo(ListNode first, ListNode second) {
        ListNode head = new ListNode(0);
        while (first != null || second != null) {
            if (first != null && second != null) {
                if (first.val > second.val) {
                    add(head, new ListNode(second.val));
                    second = second.next;
                } else if (first.val < second.val) {
                    add(head, new ListNode(first.val));
                    first = first.next;
                } else {
                    add(head, new ListNode(first.val));
                    add(head, new ListNode(second.val));
                    first = first.next;
                    second = second.next;
                }
            } else {
                while (first != null) {
                    add(head, new ListNode(first.val));
                    first = first.next;
                }
                while (second != null) {
                    add(head, new ListNode(second.val));
                    second = second.next;
                }
            }
        }
        return head.next;
    }

    private void add(ListNode head, ListNode node) {
        if (head.next == null) {
            head.next = node;
        } else {
            add(head.next, node);
        }
    }
}
```