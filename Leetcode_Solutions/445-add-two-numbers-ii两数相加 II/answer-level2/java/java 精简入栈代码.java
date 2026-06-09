### 解题思路
1.将两个链表元素分别入栈
2.将两个链表元素出栈相加
3.将所得结果以逆序放入新链表

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
        if (l1==null) return l2;
        if (l2==null) return l1; 
        Stack<Integer> stack1 = new Stack();
        Stack<Integer> stack2 = new Stack();
        int sum = 0;
        ListNode head = null;
        while(l1!=null){
            stack1.push(l1.val);
            l1 = l1.next; 
        }
        while(l2!=null){
            stack2.push(l2.val);
            l2 = l2.next; 
        }
        while(!stack1.isEmpty() || !stack2.isEmpty()||sum>0){
            int s1v = (stack1.isEmpty())?0:stack1.pop();
            int s2v = (stack2.isEmpty())?0:stack2.pop();
            sum = sum+s1v + s2v;
            ListNode node = new ListNode(sum%10);
            node.next = head;
            head = node;
            sum = sum/10;
        }
        return head;
    }
}
```