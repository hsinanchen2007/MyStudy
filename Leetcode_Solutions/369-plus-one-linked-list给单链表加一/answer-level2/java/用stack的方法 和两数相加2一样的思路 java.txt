和两数相加2的写法一模一样 就是将所有数存进stack里 然后再新建链表不断往前放

```
class Solution {
    public ListNode plusOne(ListNode head) {
        if(head == null)
            return null;
        ListNode dummy = new ListNode(-1);
        Stack<Integer> stack = new Stack<>();
        while(head != null)
        {
            stack.push(head.val);
            head = head.next;
        }
        
        int carry = 1;
        while(!stack.isEmpty())
        {
            int num = stack.pop();
            num = num + carry;
            ListNode temp = new ListNode(num % 10);
            carry = num / 10;
            temp.next = dummy.next;
            dummy.next = temp;
        }
        if(carry > 0)
        {
            ListNode temp = new ListNode(1);
            temp.next = dummy.next;
            dummy.next = temp;
        }
        return dummy.next;
    }
}
```
