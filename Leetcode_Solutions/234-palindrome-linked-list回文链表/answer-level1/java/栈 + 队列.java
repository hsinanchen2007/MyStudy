### 解题思路
遍历链表，将值放入到 栈 和 队列 中，然后分别取出比较
队列先进先出，栈先进后出，可以直接比较头尾的值

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
    public boolean isPalindrome(ListNode head) {
        Stack<Integer> stack = new Stack<>();
        Queue<Integer> queue = new LinkedList<>();
        
        while (head != null) {
            stack.add(head.val);
            queue.add(head.val);
            head = head.next;
        }
        
        while (!stack.isEmpty() && !queue.isEmpty()) {
            if (!stack.pop().equals(queue.poll())) {
                return false;
            }
        }
        
        return true;
    }
}
```