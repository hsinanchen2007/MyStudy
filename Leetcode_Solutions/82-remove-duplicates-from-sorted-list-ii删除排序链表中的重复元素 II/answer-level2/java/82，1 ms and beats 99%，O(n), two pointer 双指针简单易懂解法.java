### 解题思路
此处撰写解题思路
一开始思路是遍历两边，用hashmap存数以及重复次数，后来做到一半想了想用双指针一遍就能完事。


准备：
1. dummy节点，链表题基操
2. pre指针用于确定重复元素的最后一个位置
3. latter指针用于确定未重复元素的当前位置

思路：
1. 当发现pre与pre.next 的值不同时，此时双指针都向后移动
2. 当发现pre与pre.next 的值相同时，意味着发现重复元素，这时候latter结点停下，待pre指针找到最后一个重复元素
3. 使用内循环找到最后一个重复元素，l指向pre.next，意味着跳过中间这重复的一段；同事pre也移动
4. 上述操作完成后，相当于去掉了中间段


有一些特殊的case需要注意
比如 1-1
1-2-2-3-3-3






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
        if (head == null) {
            return null;
        }


        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode latter = dummy;
        ListNode pre = head;

        // two pointer(pre and latter), when pre != pre.next, two pointer go together
        // when pre == pre.next, latter stop going, pre go until pre != pre.next
        // stop condition: pre reach the end

        while (pre != null) {

            if (pre.next != null && pre.val == pre.next.val) {
                
                // internal circulation, stop when pre != pre.next 
                do {
                    pre = pre.next;
                } while (pre.next != null && pre.val == pre.next.val);
                
                // change pointer
                latter.next = pre.next;
                pre = pre.next;
            } else {
                
                // when pre != pre.next , two pointer move backward as the same time
                pre = pre.next;
                latter = latter.next;
            }
        }

        return dummy.next;
    }
}
```