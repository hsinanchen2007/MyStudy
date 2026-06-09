使用Long和Integer都会溢出
```
import java.math.BigDecimal;
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

        String num1 = "";
        while (!stack1.isEmpty()) {
            num1 += String.valueOf(stack1.pop());
        }

        String num2 = "";
        while (!stack2.isEmpty()) {
            num2 += String.valueOf(stack2.pop());
        }

        BigDecimal bg1 = new BigDecimal(num1);
        BigDecimal bg2 = new BigDecimal(num2);
        BigDecimal sum = bg1.add(bg2);
        String s = String.valueOf(sum);

        ListNode dump = new ListNode(-1);
        ListNode tp = dump;
        for (int i = s.length() - 1; i >= 0; i--) {
            ListNode tmp = new ListNode(Integer.parseInt(String.valueOf(s.charAt(i))));
            tp.next = tmp;
            tp = tmp;
        }
        return dump.next;
    }
}
```
