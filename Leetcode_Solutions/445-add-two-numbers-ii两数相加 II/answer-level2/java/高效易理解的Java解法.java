### 解题思路
执行用时 :2 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :44.8 MB, 在所有 java 提交中击败了86.67%的用户
思路贼简单，先把链表转化成数组再把数组转化成链表

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
       ListNode cur1 = l1;
        ListNode cur2 = l2;
        int len1 = 0;
        int len2 = 0;
        // 得到两个链表的长度
        while (cur1 != null) {
            len1++;
            cur1 = cur1.next;
        }
        while (cur2 != null) {
            len2++;
            cur2 = cur2.next;
        }
        // 初始化并填充数组,数组长度设为较长链表的长度
        int[] nodeValues;
        ListNode big, small;
        if (len1 >= len2) {
            big = l1;
            small = l2;
            nodeValues = new int[len1];
        } else {
            big = l2;
            small = l1;
            nodeValues = new int[len2];
        }
        int diff = Math.abs(len1 - len2);
        int index = 0;
        while (diff > 0) {
            nodeValues[index++] = big.val;
            big = big.next;
            diff--;
        }
        while (big != null) {
            nodeValues[index++] = big.val + small.val;
            big = big.next;
            small = small.next;
        }
        // 将数组各个位置上的值转化为一位数
        for (int i = nodeValues.length - 1; i > 0; i--) {
            if (nodeValues[i] >= 10) {
                nodeValues[i] %= 10;
                nodeValues[i - 1]++;
            }
        }
        // 最高位可能会大于等于10，进行处理
        int overflow = 0;
        if (nodeValues[0] >= 10) {
            nodeValues[0] %= 10;
            overflow = 1;
        }
        // 把数组转化成链表
        ListNode prev = new ListNode(0);
        ListNode cur = prev;
        ListNode next;
        for (int nodeValue : nodeValues) {
            next = new ListNode(nodeValue);
            cur.next = next;
            cur = cur.next;
        }
        // 判断最高位有没有多出一位
        if (overflow == 1) {
            prev.val = 1;
            return prev;
        } else {
            return prev.next;
        }
    }
}
```