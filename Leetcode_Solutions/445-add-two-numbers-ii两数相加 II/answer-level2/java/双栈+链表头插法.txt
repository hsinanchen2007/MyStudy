### 解题思路
双栈 + 头插法：
注意：
1、while循环内 除了栈或不为空以外，还需增加一个进位不为0，不然类似 5+5 的情况 则得 0，此时两个栈都为空，循环终止，然后进位为1 ，没有加入计算；
2、新建结果链表时，应创建一个空的链头，头插法后最后实则为链尾，为null；

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
                Stack<Integer> stack1 = new Stack<>();
        Stack<Integer> stack2 = new Stack<>();

        while (l1 != null) {
            stack1.push(l1.val);
            l1 = l1.next;
        }

        while (l2 != null) {
            stack2.push(l2.val);
            l2 = l2.next;
        }

        int cur = 0;
        ListNode result = null;
        while (!stack1.isEmpty() || !stack2.isEmpty() || cur != 0) {

/*          下面这样写会造成连续两次pop
            int m = stack1.pop() == null ? 0 : stack1.pop();
            int n = stack2.pop() == null ? 0 : stack2.pop();*/
            int m = stack1.isEmpty() ? 0 : stack1.pop();
            int n = stack2.isEmpty() ? 0 : stack2.pop();

            int sum = m + n + cur;
            cur = sum >= 10 ? 1 : 0;
            sum = sum % 10;

            // 链表头插法  注意前面链头定义为null
            ListNode temp = new ListNode(sum);
            temp.next = result;
            result = temp;
        }

        return result;
    }
}
```