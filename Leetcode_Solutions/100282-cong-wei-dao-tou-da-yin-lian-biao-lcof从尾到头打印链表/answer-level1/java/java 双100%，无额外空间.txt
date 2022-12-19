### 解题思路
反转链表，同时记录链表长度，翻转完成后创建数组，用翻转后的链表给数组赋值，返回数组。
![image.png](https://pic.leetcode-cn.com/6b0332ee1928bc71cd698c3615b008d8a7d59ca8f05e1f18a7dbc3e4575a22ad-image.png)

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
    public int[] reversePrint(ListNode head) {
        if (head == null) {
            return new int[]{};
        }
        ListNode pre = null;
        ListNode cur = head;
        ListNode next = cur.next;
        int len = 0;
        while(cur != null) {
            len++;
            next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        int[] res = new int[len];
        int i = 0;
        while (pre != null) {
            res[i++] = pre.val; //注意这里！！！i 一定要变，不然一直在第一个变动
            pre = pre.next;
        }
        return res;
    }
}
```