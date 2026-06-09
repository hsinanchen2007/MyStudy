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
    public int[] reversePrint(ListNode head) {
        Stack<Integer> stack = new Stack<>();
        ListNode cur = head;
        while (cur != null){
            stack.add(cur.val);
            cur = cur.next;
        }
        int[] result = new int[stack.size()];
        int index = 0;
        while (!stack.isEmpty()){
            result[index] = stack.pop();
            index++;
        }
        return result;

    }
}
```