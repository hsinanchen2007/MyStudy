### 解题思路
1. 补零。将列表补成长度相等，不足的在前面用0补充
2. 递归


### 结果
执行用时 :2 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :41.5 MB, 在所有 Java 提交中击败了86.03%的用户

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
        ListNode ans = new ListNode(-1);
        ListNode cur = ans;

        // 将补全的列表
        // 有个伪头
        ListNode ln1 = new ListNode(0);
        ListNode ln2 = new ListNode(0);
        ln1.next = l1;
        ln2.next = l2;

        fillWithZero(ln1, ln2);

        // 用补零后的链表去递归
        int carry = add(cur, ln1.next, ln2.next);

        if (carry > 0) {
            // 处理最大长度溢出的情况
            // 如 [1],[9]
            ListNode ln = new ListNode(carry);
            ln.next = ans.next;
            ans.next = ln;
        }

        return ans.next;
    }

    /**
     * 给位数较少的数据补零
     * 即 最终l1，l2 一样长
     *
     * @param l1
     * @param l2
     */
    private void fillWithZero(ListNode l1, ListNode l2) {
        ListNode p1 = l1, p2 = l2; // 移动指针
        ListNode zero1 = null, zero2 = null;

        while (p1 != null && p2 != null) {
            p1 = p1.next;
            p2 = p2.next;
        }

        while (p1 != null) {
            // 1 没结束，给 2 补零
            insertZero(l2);
            p1 = p1.next;
        }

        while (p2 != null) {
            insertZero(l1);
            p2 = p2.next;
        }

    }

    private void insertZero(ListNode ln) {
        ListNode zero = new ListNode(0);
        zero.next = ln.next;
        ln.next = zero;
    }

    /**
     * 递归
     *
     * 因为进位carry 无法像对象一样在方法中传递，
     * 所以必须return
     *
     * @param cur
     * @param l1
     * @param l2
     * @return
     */
    private int add(ListNode cur, ListNode l1, ListNode l2) {

        int carry = 0; // 进位
        int sum;

        if (l1 == null || l2 == null) {
            return 0;
        }

        // 先占个位
        // val 就是对应位置上的2值相加，后面处理进位问题
        cur.next = new ListNode(l1.val + l2.val);
        cur = cur.next;
        l1 = l1.next;
        l2 = l2.next;
        carry = add(cur, l1, l2);

        // 处理进位
        sum = cur.val + carry;
        carry = sum / 10;
        cur.val = sum % 10;

        return carry;
    }

}
```