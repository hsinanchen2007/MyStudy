### 解题思路
k个元素为一组，分组处理。
在每组中，依次把元素移到当前组的链头。

注意点：
1. 每组处理的初始状态和处理元素个数
2. 组与组之间的连接不能出错
3. 最后一组如果不完整，需要恢复原样

备注：
如果去掉分组逻辑，则退化为链表反转。


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
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null) return null;

        ListNode dummy = new ListNode(Integer.MIN_VALUE);
        dummy.next = head;

        int i = 1;

        ListNode prevEnd = dummy, start = head, end = head;
        ListNode current = head.next;
        ListNode currentNext = null;

        while (true) {

            // 处理结束后，跳出循环
            if (current == null) {

                // i != k，表示最后一组是不完全的，需要复原
                if (i != k) {
                    end = start;
                    current = start.next;
                    while (current != null) {
                        currentNext = current.next;
                        prevEnd.next = current;
                        current.next = start;
                        end.next = currentNext;

                        start = current;
                        current = currentNext;
                    }
                }

                break;
            }

            // 处理完一组数据后，重新初始化起始点，处理下一组数据
            if (i == k) {
                prevEnd = end;
                start = end = current;
                current = current.next;
                i = 1;

                continue;
            }

            // 以k为一组，把链中元素依次移到当前组的链头
            // 如原链为 1 2 3 4 5, k=3，则：
            // 第一次变为 2 1 3 4 5
            // 第二次变为 3 2 1 4 5，一组处理完成
            i++;

            currentNext = current.next;
            prevEnd.next = current;
            current.next = start;
            end.next = currentNext;

            start = current;
            current = currentNext;
        }

        return dummy.next;
    }
}
```