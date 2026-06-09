### 解题思路
此处撰写解题思路

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
        Stack<Integer> stack = new Stack<Integer>();
        while (head != null) {
            stack.add(head.val);
            head = head.next;
        }
        int start = 1;
        Integer result = 0;
        while (!stack.isEmpty()) {
            Integer temp = stack.pop();
            result += start * temp;
            start *= 2;
        }
        return result;
    }
}
```