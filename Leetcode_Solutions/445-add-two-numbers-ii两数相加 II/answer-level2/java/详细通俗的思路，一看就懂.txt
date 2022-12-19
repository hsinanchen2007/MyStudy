```java
class Solution {
    
    //一个办法是，两条链表先翻转一下，做加法再翻转回来，但是题目不允许这样
    //那基于这个思路，我们想要先操作链表的尾部，可以用栈来解决，把两条链表都放进栈就完事了！
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Stack<Integer> stack1 = new Stack<>();
        Stack<Integer> stack2 = new Stack<>();
        while(l1 != null){
            stack1.push(l1.val);
            l1 = l1.next;
        } 
        while(l2 != null){
            stack2.push(l2.val);
            l2 = l2.next;
        }
        ListNode dummy = new ListNode(0);
        int carry = 0;
        while(!stack1.isEmpty() || !stack2.isEmpty() || carry == 1){
            int val1 = stack1.isEmpty()?0:stack1.pop();
            int val2 = stack2.isEmpty()?0:stack2.pop();
            int sum = val1 + val2 + carry;
            carry = sum/10;
            int val = sum % 10;
            //头插
            ListNode node = new ListNode(val);
            node.next = dummy.next;
            dummy.next = node;
        }
        return dummy.next;

    }
}
```