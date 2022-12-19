### 解题思路
用了栈的知识，时间消耗为O(2n) = O(n) 和二进制左移消耗时间差不多

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
    public int getDecimalValue(ListNode head) {
                 if(head.val == 0 && head.next == null){
            return  0;
        }
        Stack<Integer> stack = new Stack<>();
        while (head.next!=null){
            stack.push(head.val);
            head = head.next;
        }
        //多进一位
        stack.push(head.val);
        int count = 0;
        int n = 0;
        while (!stack.empty()){
            count += stack.pop() * Math.pow(2,n);
            n++;
        }
        return count;

    }
}
```