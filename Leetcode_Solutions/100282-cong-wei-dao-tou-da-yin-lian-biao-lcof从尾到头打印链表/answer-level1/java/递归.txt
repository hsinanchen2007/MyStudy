### 解题思路
利用递归，其实本质就是用栈。。。直接用栈实现感觉更清晰
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
    private int[] result;
    private int size;
    private int index;
    public int[] reversePrint(ListNode head) {
        if (head == null) {
            result = new int[size];
            return result;
        }
        size++; 
        reversePrint(head.next);
        result[index++] = head.val;
        return result;
    }
}
```