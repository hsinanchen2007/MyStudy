### 解题思路
1、将两个链表的数据放到栈中
2、当pop的时候，就是按照从低到高的顺序出栈
3、每出一次栈，就将两个数相加
4、设置进位变量 carry = 0, 当前位的结果为 curr,如下：
eg:[7,2,4,3]
   [5,6,4]
第一次出栈：3 + 4 = 7，则carry = 0,curr = 7，头插法进链表
第二次出栈：4 + 6 = 10，则 carry = 1,curr = 0，头插法进链表
第三次出栈：2 + 5 = 7，则 carry = 0,curr = 7 + 1 = 8，头插法进链表
第四次出栈：7 + 0 = 7，则 carry = 0,curr = 7，头插法进链表

5、 每一次出栈以后将当前 curr 的值，利用链表的头插法，逆序插入链表中

执行用时 :7 ms, 在所有 Java 提交中击败了55.64%的用户
内存消耗 :45.5 MB, 在所有 Java 提交中击败了82.81%的用户

代码耗时比较高，可以再优化
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
        if (l1 == null && l2 == null) {
            return l1;
        }

        Stack<Integer> stack1 = pushStack(l1);
        Stack<Integer> stack2 = pushStack(l2);
        ListNode head = null;
        int carry = 0, index = 0;
        int length1 = stack1.size() > stack2.size() ? stack1.size() : stack2.size();
        int first = stack1.empty() ? 0 : stack1.pop();
        int second = stack2.empty() ? 0 : stack2.pop();

        while (index < length1 || carry != 0) {
            int curr = first + second + carry;
            carry = curr / 10;

            head = headPut(curr % 10, head);

            first = stack1.empty() ? 0 : stack1.pop();
            second = stack2.empty() ? 0 : stack2.pop();

            index++;
        }

        return head;
    }
    public Stack<Integer> pushStack(ListNode listNode) {
        Stack<Integer> stack = new Stack<Integer>();
        ListNode tmp = listNode;
        while (tmp != null) {
            stack.push(tmp.val);
            tmp = tmp.next;
        }
        return stack;
    }

    public ListNode headPut(int data, ListNode head) {
        ListNode node = new ListNode(data);
        node.next = head;
        head = node;
        return head;
    }
}
```