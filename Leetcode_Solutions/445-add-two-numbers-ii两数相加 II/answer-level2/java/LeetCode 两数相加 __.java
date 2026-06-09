### 解题思路
根据LeetCode2的思路来写这道题。

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
        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();
        //设置dummy节点
        ListNode dummy = new ListNode(0);
        //如果任一链表为空，返回另一链表的头节点
        if(l1 == null || l2 == null) return l1 == null ? l2 : l1;
        // 分别将两个链表的数值压栈
        while(l1 != null){
            s1.push(l1.val);
            l1 = l1.next;
        }
        while(l2 != null){
            s2.push(l2.val);
            l2 = l2.next;
        }
        int carry = 0;//carry表示进位
        //当s1不为空 或 s2不为空 或者 栈空之后存在carry进位是执行下方代码
        while(!s1.isEmpty() || !s2.isEmpty() || carry != 0){
            // 当栈不为空时，x赋值为栈的弹出值（从个位开始），栈空则补0
            int x = s1.isEmpty() ? 0 : s1.pop();
            int y = s2.isEmpty() ? 0 : s2.pop();
            int sum = x + y + carry;

            carry = sum / 10;//更新进位
            //插表法更新节点
            ListNode cur = new ListNode(sum % 10);
            cur.next = dummy.next;
            dummy.next = cur;
        }
        return dummy.next;
    }
}
```